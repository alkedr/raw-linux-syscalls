
#ifndef TEST_UTILS
#define TEST_UTILS


#define logged_open(pathname, flags) logged_open_impl(#flags, pathname, flags)
static int logged_open_impl(const char *flags_as_string, const char *pathname, int flags) {
  LOG("open(%p=\"%s\", %s)", pathname, pathname, flags_as_string);
  return open(pathname, flags);
}

static int logged_close(int fd) {
  LOG("close(fd=%d)", fd);
  return close(fd);
}

static int logged_stat(const char *pathname, struct stat *buf) {
  LOG("stat(%p=\"%s\", %p)", pathname, pathname, buf);
  return stat(pathname, buf);
}

static int logged_unlink(const char *pathname) {
  LOG("unlink(%p=\"%s\")", pathname, pathname);
  return unlink(pathname);
}

#define logged_mkdir(pathname, flags) logged_mkdir_impl(#flags, pathname, flags)
static int logged_mkdir_impl(const char *mode_as_string, const char *pathname, mode_t mode) {
  LOG("mkdir(%p=\"%s\", %s)", pathname, pathname, mode_as_string);
  return mkdir(pathname, mode);
}


#define logged_open_that_should_succeed(pathname, flags) logged_open_that_should_succeed_impl(#flags, pathname, flags)
static int logged_open_that_should_succeed_impl(const char *flags_as_string, const char *pathname, int flags) {
  int res = logged_open_impl(flags_as_string, pathname, flags);
  log_level++;
  CHECK(res > 0, "return value: expected >0, got %d", res);
  log_level--;
  return res;
}

#define logged_open_that_should_fail(pathname, flags, expected_errno) logged_open_that_should_fail_impl(#flags, #expected_errno, pathname, flags, expected_errno)
static int logged_open_that_should_fail_impl(
    const char *flags_as_string, const char *expected_errno_as_string,
    const char *pathname, int flags, int expected_errno
) {
  int res = logged_open_impl(flags_as_string, pathname, flags);
  int actual_errno = errno;
  log_level++;
  CHECK(res < 0, "return value: expected <0, got %d", res);
  CHECK(actual_errno == expected_errno, "errno: expected %d (%s), got %d", expected_errno, expected_errno_as_string, actual_errno);
  log_level--;
  return res;
}


static void logged_close_that_should_succeed(int fd) {
  int res = logged_close(fd);
  log_level++;
  CHECK(res == 0, "return value: expected 0, got %d", res);
  log_level--;
}


static void check_that_file_exists(const char *pathname) {
  LOG("check that file '%s' exists", pathname);
  log_level++;
  struct stat s;
  int res = logged_stat(pathname, &s);
  log_level++;
  CHECK(res == 0, "return value: expected 0, got %d", res);
  log_level--;
  log_level--;
}

#define check_that_file_exists_and_has_mode(pathname, expected_mode) check_that_file_exists_and_has_mode_impl(#expected_mode, pathname, expected_mode)
static void check_that_file_exists_and_has_mode_impl(const char *expected_mode_as_string, const char *pathname, mode_t expected_mode) {
  LOG("check that file '%s' exists and has mode %s", pathname, expected_mode_as_string);
  log_level++;
  struct stat s;
  int res = logged_stat(pathname, &s);
  log_level++;
  CHECK(res == 0, "return value: expected 0, got %d", res);
  CHECK(s.st_mode == expected_mode, "st_mode: expected %d (%s), got %d", expected_mode, expected_mode_as_string, s.st_mode);
  log_level--;
  log_level--;
}


static void check_that_file_does_not_exist(const char *pathname) {
  LOG("check that file '%s' does not exist", pathname);
  log_level++;
  close(logged_open_that_should_fail(pathname, 0, ENOENT));
  log_level--;
}


static void ensure_file_exists(const char *file_name) {
  LOG("ensure file '%s' exists", file_name);
  log_level++;
  logged_close_that_should_succeed(logged_open_that_should_succeed(file_name, O_CREAT));
  log_level--;
}

static void ensure_file_does_not_exist(const char *file_name) {
  LOG("ensure file '%s' does not exist", file_name);
  log_level++;
  int res = logged_unlink(file_name);
  CHECK(res == 0 || (res < 0 && errno == ENOENT), "expected either 0 or <0 and ENOENT, got %d", res);
  log_level--;
}

static void ensure_dir_exists(const char *dir_name) {
  LOG("ensure directory '%s' exists", dir_name);
  log_level++;
  int res = logged_mkdir(dir_name, S_IRWXU | S_IRWXG | S_IRWXO);
  CHECK(res == 0 || (res < 0 && errno == EEXIST), "expected either 0 or <0 and EEXIST, got %d", res);
  log_level--;
}


#endif



static void TEST_FUNCTION_NAME(0)() {
  LOG("call getpid using raw-linux-syscalls.h");
  log_level++;
  LOG("getpid()");
  log_level++;
  int res = TEST_MACRO_0(SYS_getpid);
  CHECK(res == 1, "return value: expected 1, got %d", res);
  log_level--;
  log_level--;
}


static void TEST_FUNCTION_NAME(1)() {
  const char *pathname = "/test_1_file";

  ensure_file_exists(pathname);

  LOG("call unlink using raw-linux-syscalls.h");
  log_level++;
  LOG("unlink(%p=\"%s\")", pathname, pathname);
  log_level++;
  int res = TEST_MACRO_1(SYS_unlink, pathname);
  CHECK(res == 0, "return value: expected 0, got %d", res);
  log_level--;
  log_level--;

  check_that_file_does_not_exist(pathname);
}


static void TEST_FUNCTION_NAME(2)() {
  const char *pathname = "/test_2_file";

  ensure_file_does_not_exist(pathname);

  LOG("call creat using raw-linux-syscalls.h");
  log_level++;
  LOG("creat(%p=\"%s\", S_IRWXU)", pathname, pathname);
  log_level++;
  int res = TEST_MACRO_2(SYS_creat, pathname, S_IRWXU);
  CHECK(res > 0, "return value: expected >0, got %d", res);
  log_level--;
  log_level--;

  logged_close_that_should_succeed(res);

  check_that_file_exists_and_has_mode(pathname, S_IFREG | S_IRWXU);
}


static void TEST_FUNCTION_NAME(3)() {
  const char *pathname = "/test_3_file";

  ensure_file_does_not_exist(pathname);

  LOG("call open using raw-linux-syscalls.h");
  log_level++;
  LOG("open(%p=\"%s\", O_CREAT | O_EXCL, S_IRWXU)", pathname, pathname);
  log_level++;
  int res = TEST_MACRO_3(SYS_open, pathname, O_CREAT | O_EXCL, S_IRWXU);
  CHECK(res > 0, "return value: expected >0, got %d", res);
  log_level--;
  log_level--;

  logged_close_that_should_succeed(res);

  check_that_file_exists_and_has_mode(pathname, S_IFREG | S_IRWXU);
}


static void TEST_FUNCTION_NAME(4)() {
  const char *dir_name = "/test_4_dir";
  const char *file_name = "/test_4_dir/file";
  const char *relative_file_name = "file";

  ensure_dir_exists(dir_name);
  ensure_file_does_not_exist(file_name);

  int dirfd = logged_open_that_should_succeed(dir_name, 0);

  LOG("call openat using raw-linux-syscalls.h");
  log_level++;
  LOG("openat(%d, %p=\"%s\", O_CREAT | O_EXCL, S_IRWXU)", dirfd, relative_file_name, relative_file_name);
  log_level++;
  int res = TEST_MACRO_4(SYS_openat, dirfd, relative_file_name, O_CREAT | O_EXCL, S_IRWXU);
  CHECK(res > 0, "return value: expected >0, got %d", res);
  log_level--;
  log_level--;

  logged_close_that_should_succeed(res);

  check_that_file_exists_and_has_mode(file_name, S_IFREG | S_IRWXU);
}


static void TEST_FUNCTION_NAME(5)() {
  const char *target_dir_name = "/test_4_target_dir";
  const char *link_dir_name = "/test_4_link_dir";
  const char *target_file_name = "/test_4_target_dir/target_file";
  const char *link_file_name = "/test_4_link_dir/link_file";
  const char *relative_target_file_name = "target_file";
  const char *relative_link_file_name = "link_file";

  ensure_dir_exists(target_dir_name);
  ensure_dir_exists(link_dir_name);
  ensure_file_exists(target_file_name);
  ensure_file_does_not_exist(link_file_name);

  int target_dir_fd = logged_open_that_should_succeed(target_dir_name, 0);
  int link_dir_fd = logged_open_that_should_succeed(link_dir_name, 0);

  LOG("call linkat using raw-linux-syscalls.h");
  log_level++;
  LOG("linkat(%d, %p=\"%s\", %d, %p=\"%s\", 0)", target_dir_fd, relative_target_file_name,
      relative_target_file_name, link_dir_fd, relative_link_file_name, relative_link_file_name);
  log_level++;
  int res = TEST_MACRO_5(SYS_linkat, target_dir_fd, relative_target_file_name, link_dir_fd, relative_link_file_name, 0);
  CHECK(res == 0, "return value: expected 0, got %d", res);
  log_level--;
  log_level--;

  check_that_file_exists(link_file_name);
}

