GO_LIBRARY()
IF (OS_DARWIN AND ARCH_ARM64)
    SRCS(
		exp_arenas_off.go
		exp_boringcrypto_off.go
		exp_cacheprog_off.go
		exp_cgocheck2_off.go
		exp_coverageredesign_off.go
		exp_fieldtrack_off.go
		exp_heapminimum512kib_off.go
		exp_loopvar_off.go
		exp_pagetrace_off.go
		exp_preemptibleloops_off.go
		exp_regabiargs_off.go
		exp_regabiwrappers_off.go
		exp_staticlockranking_off.go
		flags.go
    )
ELSEIF (OS_DARWIN AND ARCH_X86_64)
    SRCS(
		exp_arenas_off.go
		exp_boringcrypto_off.go
		exp_cacheprog_off.go
		exp_cgocheck2_off.go
		exp_coverageredesign_off.go
		exp_fieldtrack_off.go
		exp_heapminimum512kib_off.go
		exp_loopvar_off.go
		exp_pagetrace_off.go
		exp_preemptibleloops_off.go
		exp_regabiargs_off.go
		exp_regabiwrappers_off.go
		exp_staticlockranking_off.go
		flags.go
    )
ELSEIF (OS_LINUX AND ARCH_AARCH64)
    SRCS(
		exp_arenas_off.go
		exp_boringcrypto_off.go
		exp_cacheprog_off.go
		exp_cgocheck2_off.go
		exp_coverageredesign_off.go
		exp_fieldtrack_off.go
		exp_heapminimum512kib_off.go
		exp_loopvar_off.go
		exp_pagetrace_off.go
		exp_preemptibleloops_off.go
		exp_regabiargs_off.go
		exp_regabiwrappers_off.go
		exp_staticlockranking_off.go
		flags.go
    )
ELSEIF (OS_LINUX AND ARCH_X86_64)
    SRCS(
		exp_arenas_off.go
		exp_boringcrypto_off.go
		exp_cacheprog_off.go
		exp_cgocheck2_off.go
		exp_coverageredesign_off.go
		exp_fieldtrack_off.go
		exp_heapminimum512kib_off.go
		exp_loopvar_off.go
		exp_pagetrace_off.go
		exp_preemptibleloops_off.go
		exp_regabiargs_off.go
		exp_regabiwrappers_off.go
		exp_staticlockranking_off.go
		flags.go
    )
ELSEIF (OS_WINDOWS AND ARCH_X86_64)
    SRCS(
		exp_arenas_off.go
		exp_boringcrypto_off.go
		exp_cacheprog_off.go
		exp_cgocheck2_off.go
		exp_coverageredesign_off.go
		exp_fieldtrack_off.go
		exp_heapminimum512kib_off.go
		exp_loopvar_off.go
		exp_pagetrace_off.go
		exp_preemptibleloops_off.go
		exp_regabiargs_off.go
		exp_regabiwrappers_off.go
		exp_staticlockranking_off.go
		flags.go
    )
ENDIF()
END()
