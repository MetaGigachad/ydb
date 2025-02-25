IF (HOST_OS_DARWIN AND HOST_ARCH_X86_64)
    DECLARE_EXTERNAL_RESOURCE(TEST_TOOL_HOST sbr:5720349017)
    DECLARE_EXTERNAL_RESOURCE(TEST_TOOL3_HOST sbr:5720356281)
ELSEIF (HOST_OS_DARWIN AND HOST_ARCH_ARM64)
    DECLARE_EXTERNAL_RESOURCE(TEST_TOOL_HOST sbr:5720348354)
    DECLARE_EXTERNAL_RESOURCE(TEST_TOOL3_HOST sbr:5720355987)
ELSEIF (HOST_OS_LINUX AND HOST_ARCH_X86_64)
    DECLARE_EXTERNAL_RESOURCE(TEST_TOOL_HOST sbr:5720350134)
    DECLARE_EXTERNAL_RESOURCE(TEST_TOOL3_HOST sbr:5720356918)
ELSEIF (HOST_OS_LINUX AND HOST_ARCH_AARCH64)
    DECLARE_EXTERNAL_RESOURCE(TEST_TOOL_HOST sbr:5720347692)
    DECLARE_EXTERNAL_RESOURCE(TEST_TOOL3_HOST sbr:5720355628)
ELSEIF (HOST_OS_WINDOWS AND HOST_ARCH_X86_64)
    DECLARE_EXTERNAL_RESOURCE(TEST_TOOL_HOST sbr:5720349493)
    DECLARE_EXTERNAL_RESOURCE(TEST_TOOL3_HOST sbr:5720356619)

ENDIF()
