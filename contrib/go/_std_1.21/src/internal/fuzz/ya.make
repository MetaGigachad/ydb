GO_LIBRARY()
IF (OS_DARWIN AND ARCH_ARM64)
    SRCS(
		counters_supported.go
		coverage.go
		encoding.go
		fuzz.go
		mem.go
		minimize.go
		mutator.go
		mutators_byteslice.go
		pcg.go
		queue.go
		sys_posix.go
		trace.go
		worker.go
    )
ELSEIF (OS_DARWIN AND ARCH_X86_64)
    SRCS(
		counters_supported.go
		coverage.go
		encoding.go
		fuzz.go
		mem.go
		minimize.go
		mutator.go
		mutators_byteslice.go
		pcg.go
		queue.go
		sys_posix.go
		trace.go
		worker.go
    )
ELSEIF (OS_LINUX AND ARCH_AARCH64)
    SRCS(
		counters_supported.go
		coverage.go
		encoding.go
		fuzz.go
		mem.go
		minimize.go
		mutator.go
		mutators_byteslice.go
		pcg.go
		queue.go
		sys_posix.go
		trace.go
		worker.go
    )
ELSEIF (OS_LINUX AND ARCH_X86_64)
    SRCS(
		counters_supported.go
		coverage.go
		encoding.go
		fuzz.go
		mem.go
		minimize.go
		mutator.go
		mutators_byteslice.go
		pcg.go
		queue.go
		sys_posix.go
		trace.go
		worker.go
    )
ELSEIF (OS_WINDOWS AND ARCH_X86_64)
    SRCS(
		counters_supported.go
		coverage.go
		encoding.go
		fuzz.go
		mem.go
		minimize.go
		mutator.go
		mutators_byteslice.go
		pcg.go
		queue.go
		sys_windows.go
		trace.go
		worker.go
    )
ENDIF()
END()
