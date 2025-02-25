#include "column_features.h"
#include "index_info.h"
#include <ydb/core/formats/arrow/serializer/abstract.h>
#include <util/string/builder.h>

namespace NKikimr::NOlap {

NArrow::NTransformation::ITransformer::TPtr TColumnFeatures::GetSaveTransformer() const {
    NArrow::NTransformation::ITransformer::TPtr transformer;
    if (DictionaryEncoding) {
        transformer = DictionaryEncoding->BuildEncoder();
    }
    return transformer;
}

NArrow::NTransformation::ITransformer::TPtr TColumnFeatures::GetLoadTransformer() const {
    NArrow::NTransformation::ITransformer::TPtr transformer;
    if (DictionaryEncoding) {
        transformer = DictionaryEncoding->BuildDecoder();
    }
    return transformer;
}

void TColumnFeatures::InitLoader(const TIndexInfo& info) {
    auto schema = info.GetColumnSchema(ColumnId);
    Loader = std::make_shared<TColumnLoader>(GetLoadTransformer(), Serializer, schema, ColumnId);
}

std::optional<NKikimr::NOlap::TColumnFeatures> TColumnFeatures::BuildFromProto(const NKikimrSchemeOp::TOlapColumnDescription& columnInfo, const TIndexInfo& indexInfo) {
    const ui32 columnId = columnInfo.GetId();
    TColumnFeatures result(columnId);
    if (columnInfo.HasSerializer()) {
        AFL_VERIFY(result.Serializer.DeserializeFromProto(columnInfo.GetSerializer()));
    } else if (columnInfo.HasCompression()) {
        AFL_VERIFY(result.Serializer.DeserializeFromProto(columnInfo.GetCompression()));
    } else {
        result.Serializer = NArrow::NSerialization::TSerializerContainer::GetDefaultSerializer();
    }
    if (columnInfo.HasDictionaryEncoding()) {
        auto settings = NArrow::NDictionary::TEncodingSettings::BuildFromProto(columnInfo.GetDictionaryEncoding());
        Y_ABORT_UNLESS(settings.IsSuccess());
        result.DictionaryEncoding = *settings;
    }
    result.InitLoader(indexInfo);
    return result;
}

NKikimr::NOlap::TColumnFeatures TColumnFeatures::BuildFromIndexInfo(const ui32 columnId, const TIndexInfo& indexInfo) {
    TColumnFeatures result(columnId);
    result.InitLoader(indexInfo);
    return result;
}

TColumnFeatures::TColumnFeatures(const ui32 columnId)
    : ColumnId(columnId)
    , Serializer(NArrow::NSerialization::TSerializerContainer::GetDefaultSerializer())
{

}

TString TColumnLoader::DebugString() const {
    TStringBuilder result;
    if (ExpectedSchema) {
        result << "schema:" << ExpectedSchema->ToString() << ";";
    }
    if (Transformer) {
        result << "transformer:" << Transformer->DebugString() << ";";
    }
    if (Serializer) {
        result << "serializer:" << Serializer->DebugString() << ";";
    }
    return result;
}

} // namespace NKikimr::NOlap
