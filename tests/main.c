#include <linux/reboot.h>  /* reboot() */
#include <sys/reboot.h>  /* LINUX_REBOOT_CMD_POWER_OFF */

#define RAW_SYSCALLS_X86_64
#include <raw-linux-syscalls.h>
#include <raw-linux-syscalls.c>

#include <stdio.h>    /* puts, printf */
#include <syscall.h>  /* SYS_* */
#include <fcntl.h>    /* open, O_* */
#include <unistd.h>   /* close */
#include <errno.h>    /* E* */
#include <string.h>   /* strerror */
#include <stdarg.h>
#include <sys/stat.h>


// TODO: ptrace?
// TODO: it can test that macros have put parameters in specified registers but can't test that they are the same registers that kernel uses
// TODO: it can test macro with 6 arguments!
// TODO: it might not work on all architectures?

// TODO: Use ptrace to test wrappers for all syscalls, leave tests for macros. Tests for macros
// TODO: will test our assumptions about what registers kernel reads parameters from.


static int log_level = 0;

static void print_message(const char * message_type, const char * format, va_list args) {
  printf("%s: ", message_type);
  for (int i = 0; i < log_level; i++) {
    printf("  ");
  }
  vprintf(format, args);
  printf("\n");
}

static void LOG(const char * format, ...) {
  va_list args;
  va_start(args, format);
  print_message("LOG ", format, args);
  va_end(args);
}

static void CHECK(int condition, const char * format, ...) {
  va_list args;
  va_start(args, format);
  print_message(condition ? "PASS" : "FAIL", format, args);
  va_end(args);
}

#define run_test(test_function) do { \
  LOG(#test_function); \
  test_function(); \
  puts(""); \
} while(0);


#define TEST_FUNCTION_NAME(name) test_raw_linux_syscall_ ## name
#define TEST_MACRO_0 raw_syscall0
#define TEST_MACRO_1 raw_syscall1
#define TEST_MACRO_2 raw_syscall2
#define TEST_MACRO_3 raw_syscall3
#define TEST_MACRO_4 raw_syscall4
#define TEST_MACRO_5 raw_syscall5
#define TEST_MACRO_6 raw_syscall6
#include "tests.h"
#undef TEST_FUNCTION_NAME
#undef TEST_MACRO_0
#undef TEST_MACRO_1
#undef TEST_MACRO_2
#undef TEST_MACRO_3
#undef TEST_MACRO_4
#undef TEST_MACRO_5
#undef TEST_MACRO_6

#define TEST_FUNCTION_NAME(name) test_raw_linux_syscall_ ## name ## _without_side_effects
#define TEST_MACRO_0 raw_syscall0_without_side_effects
#define TEST_MACRO_1 raw_syscall1_without_side_effects
#define TEST_MACRO_2 raw_syscall2_without_side_effects
#define TEST_MACRO_3 raw_syscall3_without_side_effects
#define TEST_MACRO_4 raw_syscall4_without_side_effects
#define TEST_MACRO_5 raw_syscall5_without_side_effects
#define TEST_MACRO_6 raw_syscall6_without_side_effects
#include "tests.h"
#undef TEST_FUNCTION_NAME
#undef TEST_MACRO_0
#undef TEST_MACRO_1
#undef TEST_MACRO_2
#undef TEST_MACRO_3
#undef TEST_MACRO_4
#undef TEST_MACRO_5
#undef TEST_MACRO_6

#define TEST_FUNCTION_NAME(name) test_raw_linux_syscall_ ## name ## _without_memory_clobber
#define TEST_MACRO_0 raw_syscall0_without_memory_clobber
#define TEST_MACRO_1 raw_syscall1_without_memory_clobber
#define TEST_MACRO_2 raw_syscall2_without_memory_clobber
#define TEST_MACRO_3 raw_syscall3_without_memory_clobber
#define TEST_MACRO_4 raw_syscall4_without_memory_clobber
#define TEST_MACRO_5 raw_syscall5_without_memory_clobber
#define TEST_MACRO_6 raw_syscall6_without_memory_clobber
#include "tests.h"
#undef TEST_FUNCTION_NAME
#undef TEST_MACRO_0
#undef TEST_MACRO_1
#undef TEST_MACRO_2
#undef TEST_MACRO_3
#undef TEST_MACRO_4
#undef TEST_MACRO_5
#undef TEST_MACRO_6

#define TEST_FUNCTION_NAME(name) test_raw_linux_syscall_ ## name ## _without_side_effects_and_memory_clobber
#define TEST_MACRO_0 raw_syscall0_without_side_effects_and_memory_clobber
#define TEST_MACRO_1 raw_syscall1_without_side_effects_and_memory_clobber
#define TEST_MACRO_2 raw_syscall2_without_side_effects_and_memory_clobber
#define TEST_MACRO_3 raw_syscall3_without_side_effects_and_memory_clobber
#define TEST_MACRO_4 raw_syscall4_without_side_effects_and_memory_clobber
#define TEST_MACRO_5 raw_syscall5_without_side_effects_and_memory_clobber
#define TEST_MACRO_6 raw_syscall6_without_side_effects_and_memory_clobber
#include "tests.h"
#undef TEST_FUNCTION_NAME
#undef TEST_MACRO_0
#undef TEST_MACRO_1
#undef TEST_MACRO_2
#undef TEST_MACRO_3
#undef TEST_MACRO_4
#undef TEST_MACRO_5
#undef TEST_MACRO_6



int main() {
  puts("");

  run_test(test_raw_linux_syscall_0);
  run_test(test_raw_linux_syscall_1);
  run_test(test_raw_linux_syscall_2);
  run_test(test_raw_linux_syscall_3);
  run_test(test_raw_linux_syscall_4);
  run_test(test_raw_linux_syscall_5);

  run_test(test_raw_linux_syscall_0_without_side_effects);
  run_test(test_raw_linux_syscall_1_without_side_effects);
  run_test(test_raw_linux_syscall_2_without_side_effects);
  run_test(test_raw_linux_syscall_3_without_side_effects);
  run_test(test_raw_linux_syscall_4_without_side_effects);
  run_test(test_raw_linux_syscall_5_without_side_effects);

  run_test(test_raw_linux_syscall_0_without_memory_clobber);
  run_test(test_raw_linux_syscall_1_without_memory_clobber);
  run_test(test_raw_linux_syscall_2_without_memory_clobber);
  run_test(test_raw_linux_syscall_3_without_memory_clobber);
  run_test(test_raw_linux_syscall_4_without_memory_clobber);
  run_test(test_raw_linux_syscall_5_without_memory_clobber);

  run_test(test_raw_linux_syscall_0_without_side_effects_and_memory_clobber);
  run_test(test_raw_linux_syscall_1_without_side_effects_and_memory_clobber);
  run_test(test_raw_linux_syscall_2_without_side_effects_and_memory_clobber);
  run_test(test_raw_linux_syscall_3_without_side_effects_and_memory_clobber);
  run_test(test_raw_linux_syscall_4_without_side_effects_and_memory_clobber);
  run_test(test_raw_linux_syscall_5_without_side_effects_and_memory_clobber);

  reboot(LINUX_REBOOT_CMD_POWER_OFF);
  return 0;
}

