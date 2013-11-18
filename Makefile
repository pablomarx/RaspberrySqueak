
# These values should work for any Linux where the arm-linux-gnueabihf gcc
# suite is installed, including Raspbian
#
# If they don't, you'll need to manually add the paths for gcc, ld, as and
# objcopy
TOOLCHAIN_PREFIX:=arm-none-eabi-
CC:=$(TOOLCHAIN_PREFIX)gcc
LD:=$(TOOLCHAIN_PREFIX)ld
AS:=$(TOOLCHAIN_PREFIX)as
OBJCOPY:=$(TOOLCHAIN_PREFIX)objcopy

LIBGCC:=$(shell $(CC) -print-libgcc-file-name)
LIBM:=$(shell $(CC) -print-file-name=libm.a)

# Helper macros
# Find the local dir of the make file
GET_LOCAL_DIR    = $(patsubst %/,%,$(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))

# makes sure the target dir exists
MKDIR = if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi

# prepends the BUILD_DIR var to each item in the list
TOBUILDDIR = $(addprefix $(BUILDDIR)/,$(1))


# Assembler options:
# -mcpu=arm1176jzf-s will cause the assembler to error on ARM opcodes which are
# not valid for that specific processor
ASOPT=--warn -mcpu=arm1176jzf-s

# Compiler options:
# -marm prevents gcc building Thumb code
# -mcpu sets the exact CPU in the RPi, for optimised code
# -nostdinc so as not to use any system #include locations
# -ffreestanding to tell the compiler the usual system libraries aren't
# available
CCOPT=-O6 -ffreestanding -marm -mcpu=arm1176jzf-s -std=c99 -fpack-struct -Wno-packed-bitfield-compat

CFLAGS=-DSQ_CONFIG_DONE=1 -DSQUEAK_BUILTIN_PLUGIN=1 -DNO_ISNAN=1 -fshort-wchar -DTYPE_LOWLEVEL -DTARGET_RPI -DLIB_HUB -DLIB_HID -DLIB_KBD -DFINAL -Iusb -Isqueak -Ibcm2835 -Ilib

BUILDDIR=build

#
#
#
MODULE_SRCS := 

include bcm2835/rules.mk
include lib/rules.mk
include squeak/rules.mk
include usb/rules.mk

MODULE_CSRCS := $(filter %.c,$(MODULE_SRCS))
MODULE_ARM_ASMSRCS := $(filter %.s,$(MODULE_SRCS))

MODULE_COBJS := $(call TOBUILDDIR,$(patsubst %.c,%.o,$(MODULE_CSRCS)))
MODULE_ARM_ASMOBJS := $(call TOBUILDDIR,$(patsubst %.s,%.o,$(MODULE_ARM_ASMSRCS)))

all: make.dep kernel.img

clean:
	rm -rf make.dep build kernel.elf kernel.img

.PHONY: all clean

# Build the list of dependencies included at the bottom
make.dep: $(MODULE_SRCS)
	$(CC) -M $(CFLAGS) $(MODULE_SRCS) >make.dep

# If gcc -M fails, delete make.dep rather than allowing a half-finished file
# to sit around for the next build
.DELETE_ON_ERROR: make.dep

# Make an ELF kernel which loads at 0x8000 (RPi default) from all the object
# files
kernel.elf: linkscript $(MODULE_ARM_ASMOBJS) $(MODULE_COBJS)
	$(LD) -L $(BUILDDIR)/bcm2835 -T linkscript -nostdlib -nostartfiles -gc-sections -v \
		-o kernel.elf \
		$(MODULE_COBJS) $(filter-out $(BUILDDIR)/bcm2835/start.o, $(MODULE_ARM_ASMOBJS)) \
		$(LIBGCC)

# Turn the ELF kernel into a binary file. This could be combined with the
# step above, but it's easier to disassemble the ELF version to see why
# something's not working
kernel.img: kernel.elf
	$(OBJCOPY) kernel.elf -O binary kernel.img

# Generic builder for C files
$(MODULE_COBJS): $(BUILDDIR)/%.o: %.c $(MODULE_SRCDEPS)
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CCOPT) -c $< -o $@

$(MODULE_ARM_ASMOBJS): $(BUILDDIR)/%.o: %.s $(MODULE_SRCDEPS)
	@$(MKDIR)
	$(AS) $(ASOPT) -o $@ $<

# Include the auto-generated make.dep file. The hyphen before "include"
# stops it complaining that the file isn't there.
-include make.dep
