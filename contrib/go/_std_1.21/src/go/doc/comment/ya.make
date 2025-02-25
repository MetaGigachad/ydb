GO_LIBRARY()
IF (OS_DARWIN AND ARCH_ARM64)
    SRCS(
		doc.go
		html.go
		markdown.go
		parse.go
		print.go
		std.go
		text.go
    )
ELSEIF (OS_DARWIN AND ARCH_X86_64)
    SRCS(
		doc.go
		html.go
		markdown.go
		parse.go
		print.go
		std.go
		text.go
    )
ELSEIF (OS_LINUX AND ARCH_AARCH64)
    SRCS(
		doc.go
		html.go
		markdown.go
		parse.go
		print.go
		std.go
		text.go
    )
ELSEIF (OS_LINUX AND ARCH_X86_64)
    SRCS(
		doc.go
		html.go
		markdown.go
		parse.go
		print.go
		std.go
		text.go
    )
ELSEIF (OS_WINDOWS AND ARCH_X86_64)
    SRCS(
		doc.go
		html.go
		markdown.go
		parse.go
		print.go
		std.go
		text.go
    )
ENDIF()
END()
