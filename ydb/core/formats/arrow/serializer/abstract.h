#pragma once

#include <ydb/library/conclusion/status.h>
#include <ydb/services/metadata/abstract/request_features.h>
#include <ydb/services/bg_tasks/abstract/interface.h>
#include <ydb/core/protos/flat_scheme_op.pb.h>

#include <contrib/libs/apache/arrow/cpp/src/arrow/status.h>
#include <contrib/libs/apache/arrow/cpp/src/arrow/record_batch.h>
#include <util/generic/string.h>
#include <util/string/builder.h>

namespace NKikimr::NArrow::NSerialization {

class ISerializer {
protected:
    virtual TString DoSerializeFull(const std::shared_ptr<arrow::RecordBatch>& batch) const = 0;
    virtual TString DoSerializePayload(const std::shared_ptr<arrow::RecordBatch>& batch) const = 0;
    virtual arrow::Result<std::shared_ptr<arrow::RecordBatch>> DoDeserialize(const TString& data) const = 0;
    virtual arrow::Result<std::shared_ptr<arrow::RecordBatch>> DoDeserialize(const TString& data, const std::shared_ptr<arrow::Schema>& schema) const = 0;
    virtual TString DoDebugString() const {
        return "";
    }

    virtual TConclusionStatus DoDeserializeFromRequest(NYql::TFeaturesExtractor& features) = 0;

    virtual TConclusionStatus DoDeserializeFromProto(const NKikimrSchemeOp::TOlapColumn::TSerializer& proto) = 0;
    virtual void DoSerializeToProto(NKikimrSchemeOp::TOlapColumn::TSerializer& proto) const = 0;
public:
    using TPtr = std::shared_ptr<ISerializer>;
    using TFactory = NObjectFactory::TObjectFactory<ISerializer, TString>;
    using TProto = NKikimrSchemeOp::TOlapColumn::TSerializer;
    virtual ~ISerializer() = default;

    TConclusionStatus DeserializeFromRequest(NYql::TFeaturesExtractor& features) {
        return DoDeserializeFromRequest(features);
    }

    TString DebugString() const {
        return TStringBuilder() << "{class_name=" << GetClassName() << ";details={" << DoDebugString() << "}}";
    }

    TConclusionStatus DeserializeFromProto(const NKikimrSchemeOp::TOlapColumn::TSerializer& proto) {
        return DoDeserializeFromProto(proto);
    }

    void SerializeToProto(NKikimrSchemeOp::TOlapColumn::TSerializer& proto) const {
        return DoSerializeToProto(proto);
    }

    TString SerializeFull(const std::shared_ptr<arrow::RecordBatch>& batch) const {
        return DoSerializeFull(batch);
    }

    TString SerializePayload(const std::shared_ptr<arrow::RecordBatch>& batch) const {
        return DoSerializePayload(batch);
    }

    arrow::Result<std::shared_ptr<arrow::RecordBatch>> Deserialize(const TString& data) const {
        if (!data) {
            return nullptr;
        }
        return DoDeserialize(data);
    }

    arrow::Result<std::shared_ptr<arrow::RecordBatch>> Deserialize(const TString& data, const std::shared_ptr<arrow::Schema>& schema) const {
        if (!data) {
            return nullptr;
        }
        return DoDeserialize(data, schema);
    }

    virtual bool IsHardPacker() const = 0;

    virtual TString GetClassName() const = 0;
};

class TSerializerContainer: public NBackgroundTasks::TInterfaceProtoContainer<ISerializer> {
private:
    using TBase = NBackgroundTasks::TInterfaceProtoContainer<ISerializer>;
public:
    using TBase::TBase;

    TSerializerContainer(const std::shared_ptr<ISerializer>& object)
        : TBase(object)
    {

    }

    TString DebugString() const {
        if (GetObjectPtr()) {
            return GetObjectPtr()->DebugString();
        } else {
            return "NO_OBJECT";
        }
    }
    using TBase::DeserializeFromProto;

    static std::shared_ptr<ISerializer> GetDefaultSerializer();

    TConclusionStatus DeserializeFromProto(const NKikimrSchemeOp::TCompressionOptions& proto);

    TConclusionStatus DeserializeFromRequest(NYql::TFeaturesExtractor& features);
};

}
