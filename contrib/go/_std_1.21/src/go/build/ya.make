GO_LIBRARY()
IF (OS_DARWIN AND ARCH_ARM64)
    SRCS(
		build.go
		doc.go
		gc.go
		read.go
		syslist.go
		zcgo.go
    )
ELSEIF (OS_DARWIN AND ARCH_X86_64)
    SRCS(
		build.go
		doc.go
		gc.go
		read.go
		syslist.go
		zcgo.go
    )
ELSEIF (OS_LINUX AND ARCH_AARCH64)
    SRCS(
		build.go
		doc.go
		gc.go
		read.go
		syslist.go
		zcgo.go
    )
ELSEIF (OS_LINUX AND ARCH_X86_64)
    SRCS(
		build.go
		doc.go
		gc.go
		read.go
		syslist.go
		zcgo.go
    )
ELSEIF (OS_WINDOWS AND ARCH_X86_64)
    SRCS(
		build.go
		doc.go
		gc.go
		read.go
		syslist.go
		zcgo.go
    )
ENDIF()
END()


RECURSE(
	constraint
)
