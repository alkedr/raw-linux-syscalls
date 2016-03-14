#ifndef zQ4Wsh6VU6_HEADER_GUARD_RAW_LINUX_SYSCALLS_H
#define zQ4Wsh6VU6_HEADER_GUARD_RAW_LINUX_SYSCALLS_H



#if !defined(RAW_SYSCALLS_AARCH64) \
 && !defined(RAW_SYSCALLS_ARM) \
 && !defined(RAW_SYSCALLS_I386) \
 && !defined(RAW_SYSCALLS_MICROBLAZE) \
 && !defined(RAW_SYSCALLS_MIPS) \
 && !defined(RAW_SYSCALLS_OR1K) \
 && !defined(RAW_SYSCALLS_POWERPC) \
 && !defined(RAW_SYSCALLS_SH) \
 && !defined(RAW_SYSCALLS_X32) \
 && !defined(RAW_SYSCALLS_X86_64)

// TODO: detect arch

#endif



#ifndef RAW_LINUX_SYSCALLS_REGISTER_TYPE
// TODO: detect
#define RAW_LINUX_SYSCALLS_REGISTER_TYPE long
#endif



#ifndef RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS
#define RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS static
#endif



#define SET_OF_PRIVATE_SYSCALL_METHOD_DECLARATIONS(NAME_SUFFIX) \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_0 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
  );                                                            \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_1 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a1                       \
  );                                                            \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_2 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a1                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a2                       \
  );                                                            \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_3 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a1                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a2                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a3                       \
  );                                                            \
                                                                \
  RAW_LINUX_SYSCALLS_METHOD_SPECIFIERS                          \
  RAW_LINUX_SYSCALLS_REGISTER_TYPE                              \
  raw_linux_syscalls_private_syscall_4 ## NAME_SUFFIX (         \
    RAW_LINUX_SYSCALLS_REGISTER_TYPE n                          \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a1                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a2                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a3                       \
    , RAW_LINUX_SYSCALLS_REGISTER_TYPE a4                       \
  );                                                            \
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
  );                                                            \
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
  );

SET_OF_PRIVATE_SYSCALL_METHOD_DECLARATIONS()
SET_OF_PRIVATE_SYSCALL_METHOD_DECLARATIONS(_without_side_effects)
SET_OF_PRIVATE_SYSCALL_METHOD_DECLARATIONS(_without_memory_clobber)
SET_OF_PRIVATE_SYSCALL_METHOD_DECLARATIONS(_without_side_effects_and_memory_clobber)

#undef SET_OF_PRIVATE_SYSCALL_METHOD_DECLARATIONS



#define raw_syscall0(N) \
  raw_linux_syscalls_private_syscall_0( \
    N \
  )

#define raw_syscall1(N, A1) \
  raw_linux_syscalls_private_syscall_1( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
  )

#define raw_syscall2(N, A1, A2) \
  raw_linux_syscalls_private_syscall_2( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
  )

#define raw_syscall3(N, A1, A2, A3) \
  raw_linux_syscalls_private_syscall_3( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
  )

#define raw_syscall4(N, A1, A2, A3, A4) \
  raw_linux_syscalls_private_syscall_4( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
  )

#define raw_syscall5(N, A1, A2, A3, A4, A5) \
  raw_linux_syscalls_private_syscall_5( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A5) \
  )

#define raw_syscall6(N, A1, A2, A3, A4, A5, A6) \
  raw_linux_syscalls_private_syscall_6( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A5) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A6) \
  )



#define raw_syscall0_without_side_effects(N) \
  raw_linux_syscalls_private_syscall_0_without_side_effects( \
    N \
  )

#define raw_syscall1_without_side_effects(N, A1) \
  raw_linux_syscalls_private_syscall_1_without_side_effects( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
  )

#define raw_syscall2_without_side_effects(N, A1, A2) \
  raw_linux_syscalls_private_syscall_2_without_side_effects( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
  )

#define raw_syscall3_without_side_effects(N, A1, A2, A3) \
  raw_linux_syscalls_private_syscall_3_without_side_effects( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
  )

#define raw_syscall4_without_side_effects(N, A1, A2, A3, A4) \
  raw_linux_syscalls_private_syscall_4_without_side_effects( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
  )

#define raw_syscall5_without_side_effects(N, A1, A2, A3, A4, A5) \
  raw_linux_syscalls_private_syscall_5_without_side_effects( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A5) \
  )

#define raw_syscall6_without_side_effects(N, A1, A2, A3, A4, A5, A6) \
  raw_linux_syscalls_private_syscall_6_without_side_effects( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A5) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A6) \
  )



#define raw_syscall0_without_memory_clobber(N) \
  raw_linux_syscalls_private_syscall_0_without_memory_clobber( \
    N \
  )

#define raw_syscall1_without_memory_clobber(N, A1) \
  raw_linux_syscalls_private_syscall_1_without_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
  )

#define raw_syscall2_without_memory_clobber(N, A1, A2) \
  raw_linux_syscalls_private_syscall_2_without_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
  )

#define raw_syscall3_without_memory_clobber(N, A1, A2, A3) \
  raw_linux_syscalls_private_syscall_3_without_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
  )

#define raw_syscall4_without_memory_clobber(N, A1, A2, A3, A4) \
  raw_linux_syscalls_private_syscall_4_without_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
  )

#define raw_syscall5_without_memory_clobber(N, A1, A2, A3, A4, A5) \
  raw_linux_syscalls_private_syscall_5_without_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A5) \
  )

#define raw_syscall6_without_memory_clobber(N, A1, A2, A3, A4, A5, A6) \
  raw_linux_syscalls_private_syscall_6_without_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A5) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A6) \
  )



#define raw_syscall0_without_side_effects_and_memory_clobber(N) \
  raw_linux_syscalls_private_syscall_0_without_side_effects_and_memory_clobber( \
    N \
  )

#define raw_syscall1_without_side_effects_and_memory_clobber(N, A1) \
  raw_linux_syscalls_private_syscall_1_without_side_effects_and_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
  )

#define raw_syscall2_without_side_effects_and_memory_clobber(N, A1, A2) \
  raw_linux_syscalls_private_syscall_2_without_side_effects_and_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
  )

#define raw_syscall3_without_side_effects_and_memory_clobber(N, A1, A2, A3) \
  raw_linux_syscalls_private_syscall_3_without_side_effects_and_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
  )

#define raw_syscall4_without_side_effects_and_memory_clobber(N, A1, A2, A3, A4) \
  raw_linux_syscalls_private_syscall_4_without_side_effects_and_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
  )

#define raw_syscall5_without_side_effects_and_memory_clobber(N, A1, A2, A3, A4, A5) \
  raw_linux_syscalls_private_syscall_5_without_side_effects_and_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A5) \
  )

#define raw_syscall6_without_side_effects_and_memory_clobber(N, A1, A2, A3, A4, A5, A6) \
  raw_linux_syscalls_private_syscall_6_without_side_effects_and_memory_clobber( \
    N \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A1) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A2) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A3) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A4) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A5) \
    , (RAW_LINUX_SYSCALLS_REGISTER_TYPE)(A6) \
  )



// TODO: variadic macro raw_syscall() if c standard is C99 or C++11 or higher?


// TODO: all syscalls for current arch
// TODO: vdso, passing 64-bit parameters in 32-bit registers

//#define RAW_SYSCALLS_IO_SETUP 0


//#define raw_io_setup(A1, A2) raw_syscall2(RAW_SYSCALLS_IO_SETUP, A1, A2)




#endif

