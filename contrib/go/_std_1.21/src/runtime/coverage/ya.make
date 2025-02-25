GO_LIBRARY()
IF (OS_DARWIN AND ARCH_ARM64)
    SRCS(
		apis.go
		dummy.s
		emit.go
		hooks.go
		testsupport.go
    )
ELSEIF (OS_DARWIN AND ARCH_X86_64)
    SRCS(
		apis.go
		dummy.s
		emit.go
		hooks.go
		testsupport.go
    )
ELSEIF (OS_LINUX AND ARCH_AARCH64)
    SRCS(
		apis.go
		dummy.s
		emit.go
		hooks.go
		testsupport.go
    )
ELSEIF (OS_LINUX AND ARCH_X86_64)
    SRCS(
		apis.go
		dummy.s
		emit.go
		hooks.go
		testsupport.go
    )
ELSEIF (OS_WINDOWS AND ARCH_X86_64)
    SRCS(
		apis.go
		dummy.s
		emit.go
		hooks.go
		testsupport.go
    )
ENDIF()
END()
