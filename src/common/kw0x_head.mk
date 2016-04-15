.PHONY:         clean
.SUFFIXES:
MKDIR_P         = mkdir -p
TOOLCHAIN_PATH  = ../../tools/toolchain
OPENOCD_DIR     = $(TOOLCHAIN_PATH)
OOCD_CFG        = $(TOOLCHAIN_PATH)/olimex_swd_kinetis.cfg
GDB_CFG         = $(TOOLCHAIN_PATH)/gdboocd_ocd.cmd
LINKER_SCRIPT   = $(TOOLCHAIN_PATH)/MKW01Z128.ld
OPENOCD_HEXFILE = c3.hex
ARCH            = arm-none-eabi
CC              = $(ARCH)-gcc
AS              = $(ARCH)-as
INCDIR          = -I. -I../common -I../drivers -I/usr/local/arm-none-eabi/include 
CPPFLAGS        = $(INCDIR)
CFLAGS          = -mthumb -mcpu=cortex-m0 -ffreestanding -fno-common -ggdb3 -std=gnu11
LDFLAGS         = --specs=nosys.specs -static -nostartfiles -T$(LINKER_SCRIPT)
DRIVER_CSRCS    = $(wildcard ../drivers/*.c)
DRIVER_COBJS    = $(DRIVER_CSRCS:.c=.o)
COMM_CSRCS      = $(KW0X_COMMON_PATH)/crt0.c
COMM_COBJS      = $(COMM_CSRCS:.c=.o)





