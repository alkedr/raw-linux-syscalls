ARCHITECTURES ?= x86_64

LINUX_VERSION ?= 4.4.3
LINUX_DIST ?= work/dist-linux-$(LINUX_VERSION).tar.xz
$(LINUX_DIST)_URL ?= https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-$(LINUX_VERSION).tar.xz

BINUTILS_VERSION ?= 2.26
BINUTILS_DIST ?= work/dist-binutils-$(BINUTILS_VERSION).tar.bz2
$(BINUTILS_DIST)_URL ?= http://ftp.gnu.org/gnu/binutils/binutils-$(BINUTILS_VERSION).tar.bz2

GCC_VERSION ?= 5.3.0
GCC_DIST ?= work/dist-gcc-$(GCC_VERSION).tar.bz2
$(GCC_DIST)_URL ?= http://mirror.tochlab.net/pub/gnu/gcc/gcc-$(GCC_VERSION)/gcc-$(GCC_VERSION).tar.bz2

MPFR_VERSION ?= 3.1.3
MPFR_DIST ?= work/dist-mpfr-$(MPFR_VERSION).tar.xz
$(MPFR_DIST)_URL ?= http://ftpmirror.gnu.org/mpfr/mpfr-$(MPFR_VERSION).tar.xz

GMP_VERSION ?= 6.1.0
GMP_DIST ?= work/dist-gmp-$(GMP_VERSION).tar.xz
$(GMP_DIST)_URL ?= http://ftpmirror.gnu.org/gmp/gmp-$(GMP_VERSION).tar.xz

MPC_VERSION ?= 1.0.3
MPC_DIST ?= work/dist-mpc-$(MPC_VERSION).tar.gz
$(MPC_DIST)_URL ?= http://ftpmirror.gnu.org/mpc/mpc-$(MPC_VERSION).tar.gz

ISL_VERSION ?= 0.16.1
ISL_DIST ?= work/dist-isl-$(ISL_VERSION).tar.bz2
$(ISL_DIST)_URL ?= ftp://gcc.gnu.org/pub/gcc/infrastructure/isl-$(ISL_VERSION).tar.bz2

CLOOG_VERSION ?= 0.18.1
CLOOG_DIST ?= work/dist-cloog-$(CLOOG_VERSION).tar.gz
$(CLOOG_DIST)_URL ?= ftp://gcc.gnu.org/pub/gcc/infrastructure/cloog-$(CLOOG_VERSION).tar.gz


# disables implicit rules
.SUFFIXES:

# makes make never delete intermediate files
.SECONDARY:

# allows $@ in prerequisite list
.SECONDEXPANSION:


# TODO: multiple compilers for tests (different versions of gcc and clang, different standards, maybe something else?)
# TODO: do we need gcc's optional libraries?

# TODO: test preprocessor symbols

test: $(addprefix test-,$(ARCHITECTURES))

test-x86_64: work/linux-$(LINUX_VERSION)-image-x86_64 work/initramfs-x86_64.cpio
	qemu-system-x86_64 -nographic -kernel $(word 1,$^) -initrd $(word 2,$^)


work/:
	mkdir $@


work/dist-%: | work/
	wget -O- $($@_URL) > $@


work/src-binutils-$(BINUTILS_VERSION): $(BINUTILS_DIST) | work/
	rm -rf $@ && mkdir $@ && tar -xf $(BINUTILS_DIST) -C $@ --strip-components=1

work/src-gcc-$(GCC_VERSION): $(GCC_DIST) $(MPFR_DIST) $(GMP_DIST) $(MPC_DIST) $(ISL_DIST) $(CLOOG_DIST) | work/
	rm -rf $@ && mkdir $@ && tar -xf $(GCC_DIST) -C $@ --strip-components=1
	mkdir $@/mpfr && tar -xf $(MPFR_DIST) -C $@/mpfr --strip-components=1
	mkdir $@/gmp && tar -xf $(GMP_DIST) -C $@/gmp --strip-components=1
	mkdir $@/mpc && tar -xf $(MPC_DIST) -C $@/mpc --strip-components=1
	mkdir $@/isl && tar -xf $(ISL_DIST) -C $@/isl --strip-components=1
	mkdir $@/cloog && tar -xf $(CLOOG_DIST) -C $@/cloog --strip-components=1

work/src-linux-$(LINUX_VERSION): $(LINUX_DIST) | work/
	rm -rf $@ && mkdir $@ && tar -xf $< -C $@ --strip-components=1


work/build-binutils-$(BINUTILS_VERSION)-%: work/src-binutils-$(BINUTILS_VERSION) | work/
	rm -rf $@ && mkdir $@
	# TODO: disable nls, man, -g, gprof, multilib?, maintainer mode, install into /bin?
	cd $@ && ../../$</configure --disable-multilib # --target=x86_64-pc-linux-gnu
	make -C $@ V=0

work/build-gcc-$(GCC_VERSION)-%: work/src-gcc-$(GCC_VERSION) | work/
	rm -rf $@ && mkdir $@
	# TODO: --disable-libquadmath --disable-libada --disable-libssp --disable-libstdcxx --disable-lto --disable-dependency-tracking ?
	# TODO: --disable-plugins --disable-multilib
	# TODO: make V=0 ?
	# TODO: disable -g ?
	# TODO: need to disable libcxx explicitly
	#cd $@ && ../../$</configure --disable-multilib #--target=x86_64-pc-linux-gnu #--enable-languages=c --disable-bootstrap
	cd $@ && ../../$</configure --disable-multilib --disable-bootstrap --enable-languages=c
	make -C $@ V=0

work/build-linux-$(LINUX_VERSION)-%: work/src-linux-$(LINUX_VERSION) tests/linux-config-% work/toolchain-% | work/
	rm -rf $@ && mkdir $@
	cp $(word 2,$^) $@/.config
	make -C $(word 1,$^) O=../../$@ CROSS_COMPILE=`pwd`/$(word 3,$^)/usr/local/bin/


work/toolchain-%: work/build-binutils-$(BINUTILS_VERSION)-% work/build-gcc-$(GCC_VERSION)-% | work/
	rm -rf $@ && mkdir $@
	make -C $(word 1,$^) install DESTDIR=`pwd`/$@
	make -C $(word 2,$^) install DESTDIR=`pwd`/$@

work/linux-$(LINUX_VERSION)-image-%: work/build-linux-$(LINUX_VERSION)-% | work/
	cp $</arch/`echo $< | grep -o '[^-]*$$'`/boot/bzImage $@

work/initramfs-%.cpio: work/initramfs-%/init | work/
	cd $(dir $<) && ls | cpio -H newc -ov > ../../$@

work/initramfs-%/init: work/tests-% | work/
	mkdir -p $(dir $@) && cp $< $@

# TODO: depends on ALL tests and code
# TODO: use cross-compiler
# TODO: all warnings and strictest standard
work/tests-%: $(wildcard tests/*.h) $(wildcard tests/*.c) raw-linux-syscalls.h raw-linux-syscalls.c Makefile | work/
	gcc -static -Wall -Wextra -pedantic -I. $(wildcard tests/*.c) -o $@   # TODO ansi

