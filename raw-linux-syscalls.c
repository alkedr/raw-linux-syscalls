#ifndef zQ4Wsh6VU6_HEADER_GUARD_RAW_LINUX_SYSCALLS_C
#define zQ4Wsh6VU6_HEADER_GUARD_RAW_LINUX_SYSCALLS_C


#include <raw-linux-syscalls.h>


// TODO: vdso


#if defined(RAW_SYSCALLS_AARCH64)


// TODO


#elif defined(RAW_SYSCALLS_ARM)


// TODO


#elif defined(RAW_SYSCALLS_I386)


// TODO


#elif defined(RAW_SYSCALLS_MICROBLAZE)


// TODO


#elif defined(RAW_SYSCALLS_MIPS)


// TODO


#elif defined(RAW_SYSCALLS_OR1K)


// TODO


#elif defined(RAW_SYSCALLS_POWERPC)


// TODO


#elif defined(RAW_SYSCALLS_SH)


// TODO


#elif defined(RAW_SYSCALLS_X32)


// TODO


#elif defined(RAW_SYSCALLS_X86_64)


#define CLOBBERS_WITHOUT_MEMORY "rcx", "r11"
#define DEFAULT_CLOBBERS CLOBBERS_WITHOUT_MEMORY, "memory"

#define SYSCALL_0_IMPL(VOLATILE, CLOBBERS) \
  __asm__ VOLATILE ("syscall" : "=a"(ret) : "a"(n) : CLOBBERS);

#define SYSCALL_1_IMPL(VOLATILE, CLOBBERS) \
  __asm__ VOLATILE ("syscall" : "=a"(ret) : "a"(n), "D"(a1) : CLOBBERS);

#define SYSCALL_2_IMPL(VOLATILE, CLOBBERS) \
  __asm__ VOLATILE ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2) : CLOBBERS);

#define SYSCALL_3_IMPL(VOLATILE, CLOBBERS) \
  __asm__ VOLATILE ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3) : CLOBBERS);

#define SYSCALL_4_IMPL(VOLATILE, CLOBBERS) \
	register RAW_LINUX_SYSCALLS_REGISTER_TYPE r10 __asm__("r10") = a4; \
	__asm__ VOLATILE ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10): CLOBBERS);

#define SYSCALL_5_IMPL(VOLATILE, CLOBBERS) \
	register RAW_LINUX_SYSCALLS_REGISTER_TYPE r10 __asm__("r10") = a4; \
	register RAW_LINUX_SYSCALLS_REGISTER_TYPE r8 __asm__("r8") = a5; \
	__asm__ VOLATILE ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8) : CLOBBERS);

#define SYSCALL_6_IMPL(VOLATILE, CLOBBERS) \
	register RAW_LINUX_SYSCALLS_REGISTER_TYPE r10 __asm__("r10") = a4; \
	register RAW_LINUX_SYSCALLS_REGISTER_TYPE r8 __asm__("r8") = a5; \
	register RAW_LINUX_SYSCALLS_REGISTER_TYPE r9 __asm__("r9") = a6; \
	__asm__ VOLATILE ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8), "r"(r9) : CLOBBERS);


#endif



#define SET_OF_PRIVATE_SYSCALL_METHOD_DEFINITIONS(NAME_SUFFIX, IMPL_0, IMPL_1, IMPL_2, IMPL_3, IMPL_4, IMPL_5, IMPL_6) \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_0 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
  ) {                                                           \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE ret;                       \
	  IMPL_0                                                      \
	  return ret;                                                 \
  }                                                             \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_1 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a1                       \
  ) {                                                           \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE ret;                       \
	  IMPL_1                                                      \
	  return ret;                                                 \
  }                                                             \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_2 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a1                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a2                       \
  ) {                                                           \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE ret;                       \
	  IMPL_2                                                      \
	  return ret;                                                 \
  }                                                             \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_3 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a1                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a2                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a3                       \
  ) {                                                           \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE ret;                       \
	  IMPL_3                                                      \
	  return ret;                                                 \
  }                                                             \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_4 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a1                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a2                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a3                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a4                       \
  ) {                                                           \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE ret;                       \
	  IMPL_4                                                      \
	  return ret;                                                 \
  }                                                             \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_5 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a1                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a2                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a3                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a4                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a5                       \
  ) {                                                           \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE ret;                       \
	  IMPL_5                                                      \
	  return ret;                                                 \
  }                                                             \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_6 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a1                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a2                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a3                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a4                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a5                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a6                       \
  ) {                                                           \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE ret;                       \
	  IMPL_6                                                      \
	  return ret;                                                 \
  }


SET_OF_PRIVATE_SYSCALL_METHOD_DEFINITIONS(
  , SYSCALL_0_IMPL(__volatile__, DEFAULT_CLOBBERS)
  , SYSCALL_1_IMPL(__volatile__, DEFAULT_CLOBBERS)
  , SYSCALL_2_IMPL(__volatile__, DEFAULT_CLOBBERS)
  , SYSCALL_3_IMPL(__volatile__, DEFAULT_CLOBBERS)
  , SYSCALL_4_IMPL(__volatile__, DEFAULT_CLOBBERS)
  , SYSCALL_5_IMPL(__volatile__, DEFAULT_CLOBBERS)
  , SYSCALL_6_IMPL(__volatile__, DEFAULT_CLOBBERS)
)

SET_OF_PRIVATE_SYSCALL_METHOD_DEFINITIONS(
  _without_side_effects
  , SYSCALL_0_IMPL(, DEFAULT_CLOBBERS)
  , SYSCALL_1_IMPL(, DEFAULT_CLOBBERS)
  , SYSCALL_2_IMPL(, DEFAULT_CLOBBERS)
  , SYSCALL_3_IMPL(, DEFAULT_CLOBBERS)
  , SYSCALL_4_IMPL(, DEFAULT_CLOBBERS)
  , SYSCALL_5_IMPL(, DEFAULT_CLOBBERS)
  , SYSCALL_6_IMPL(, DEFAULT_CLOBBERS)
)

SET_OF_PRIVATE_SYSCALL_METHOD_DEFINITIONS(
  _without_memory_clobber
  , SYSCALL_0_IMPL(__volatile__, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_1_IMPL(__volatile__, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_2_IMPL(__volatile__, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_3_IMPL(__volatile__, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_4_IMPL(__volatile__, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_5_IMPL(__volatile__, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_6_IMPL(__volatile__, CLOBBERS_WITHOUT_MEMORY)
)

SET_OF_PRIVATE_SYSCALL_METHOD_DEFINITIONS(
  _without_side_effects_and_memory_clobber
  , SYSCALL_0_IMPL(, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_1_IMPL(, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_2_IMPL(, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_3_IMPL(, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_4_IMPL(, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_5_IMPL(, CLOBBERS_WITHOUT_MEMORY)
  , SYSCALL_6_IMPL(, CLOBBERS_WITHOUT_MEMORY)
)


#undef CLOBBERS_WITHOUT_MEMORY
#undef DEFAULT_CLOBBERS
#undef SET_OF_PRIVATE_SYSCALL_METHOD_DEFINITIONS


#endif

