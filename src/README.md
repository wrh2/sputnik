# src directory

* Source for firmware in this directory

* common/

Common link files, make templates and header files for all experiments

* drivers/

Common drivers for spi, uart etc.

## Rebuild all projects

* Run make in this directory

```

.~/.../PSAS/sputnik/src (reorg*) > make
make -s -w -C rx rebuild
make[1]: Entering directory '/home/kwilson/Projects/PSAS/sputnik/src/rx'
make[2]: Entering directory '/home/kwilson/Projects/PSAS/sputnik/src/rx'
-------- COMPILING ../drivers/uart.s 
-------- COMPILING ../drivers/uart.o 
-------- COMPILING ../drivers/spi.s 
-------- COMPILING ../drivers/spi.o 
-------- COMPILING ../drivers/port.s 
-------- COMPILING ../drivers/port.o 
-------- COMPILING ../drivers/transceiver.s 
-------- COMPILING ../drivers/transceiver.o 
-------- COMPILING rx.s 
-------- COMPILING rx.o 
-------- COMPILING ../common/crt0.s 
-------- COMPILING ../common/crt0.o 
-------- LINKING rx 
make[2]: Leaving directory '/home/kwilson/Projects/PSAS/sputnik/src/rx'
make[1]: Leaving directory '/home/kwilson/Projects/PSAS/sputnik/src/rx'
make -s -w -C tx rebuild
make[1]: Entering directory '/home/kwilson/Projects/PSAS/sputnik/src/tx'
make[2]: Entering directory '/home/kwilson/Projects/PSAS/sputnik/src/tx'
-------- COMPILING ../drivers/uart.s 
-------- COMPILING ../drivers/uart.o 
-------- COMPILING ../drivers/spi.s 
-------- COMPILING ../drivers/spi.o 
-------- COMPILING ../drivers/port.s 
-------- COMPILING ../drivers/port.o 
-------- COMPILING ../drivers/transceiver.s 
-------- COMPILING ../drivers/transceiver.o 
-------- COMPILING tx.s 
-------- COMPILING tx.o 
-------- COMPILING ../common/crt0.s 
-------- COMPILING ../common/crt0.o 
-------- LINKING tx 
make[2]: Leaving directory '/home/kwilson/Projects/PSAS/sputnik/src/tx'
make[1]: Leaving directory '/home/kwilson/Projects/PSAS/sputnik/src/tx'
make -s -w -C blinky rebuild
make[1]: Entering directory '/home/kwilson/Projects/PSAS/sputnik/src/blinky'
make[2]: Entering directory '/home/kwilson/Projects/PSAS/sputnik/src/blinky'
-------- COMPILING ../drivers/uart.s 
-------- COMPILING ../drivers/uart.o 
-------- COMPILING ../drivers/spi.s 
-------- COMPILING ../drivers/spi.o 
-------- COMPILING ../drivers/port.s 
-------- COMPILING ../drivers/port.o 
-------- COMPILING ../drivers/transceiver.s 
-------- COMPILING ../drivers/transceiver.o 
-------- COMPILING blinky.s 
-------- COMPILING blinky.o 
-------- COMPILING ../common/crt0.s 
-------- COMPILING ../common/crt0.o 
-------- LINKING blinky 
make[2]: Leaving directory '/home/kwilson/Projects/PSAS/sputnik/src/blinky'
make[1]: Leaving directory '/home/kwilson/Projects/PSAS/sputnik/src/blinky'


```

## Writing to flash

* Use the make write target (maybe sudo make write)
 * Connect an ARM-USB-TINY-H with the SWD adapter.

```

~/.../sputnik/src/blinky (reorg*) > make clean && make -j4 && sudo make write
rm -f blinky *.o *.hex *.s ../drivers/*.s ../drivers/*.o ../common/*.o
-------- COMPILING ../drivers/transceiver.s 
-------- COMPILING ../drivers/uart.s 
-------- COMPILING ../drivers/port.s 
-------- COMPILING ../drivers/spi.s 
-------- COMPILING blinky.s 
-------- COMPILING ../common/crt0.s 
-------- COMPILING ../drivers/spi.o 
-------- COMPILING ../drivers/uart.o 
-------- COMPILING ../drivers/port.o 
-------- COMPILING ../drivers/transceiver.o 
-------- COMPILING ../common/crt0.o 
-------- COMPILING blinky.o 
-------- LINKING blinky 
rm ../drivers/port.s ../common/crt0.s ../drivers/transceiver.s ../drivers/spi.s blinky.s ../drivers/uart.s
-------- CREATE HEX FILE blinky.hex 
-------- SEND HEX FILE TO FLASH
Open On-Chip Debugger 0.9.0 (2015-05-19-13:50)
Licensed under GNU GPL v2
For bug reports, read
	http://openocd.org/doc/doxygen/bugs.html
Info : FTDI SWD mode enabled
Info : add flash_bank kinetis kw01.flash
adapter speed: 1000 kHz
srst_only separate srst_nogate srst_open_drain connect_deassert_srst
cortex_m reset_config sysresetreq
Info : clock speed 1000 kHz
Info : SWD IDCODE 0x0bc11477
Info : kw01.cpu: hardware has 2 breakpoints, 2 watchpoints
invalid subcommand "disable_wdog"
in procedure 'program' 
in procedure 'init' called at file "embedded:startup.tcl", line 473
in procedure 'ocd_bouncer' 
in procedure 'kinetis'

invalid subcommand "disable_wdog"
in procedure 'program' 
in procedure 'reset' called at file "embedded:startup.tcl", line 478
in procedure 'ocd_bouncer' 
in procedure 'ocd_process_reset' 
in procedure 'ocd_process_reset_inner' called at file "embedded:startup.tcl", line 248
in procedure 'kw01.cpu' called at file "embedded:startup.tcl", line 299
in procedure 'ocd_bouncer' 
in procedure 'kinetis'

target state: halted
target halted due to debug-request, current mode: Thread 
xPSR: 0x81000000 pc: 0x00000414 msp: 0x1ffff400
** Programming Started **
auto erase enabled
Info : Probing flash info for bank 0
Info : Padding image section 0 with 832 bytes
Info : Padding image section 1 with 4 bytes
Warn : flash configuration field erased, please reset the device
Warn : Kinetis L Series supports Program Longword execution only.
Info : Kinetis: FLASH Write ...
wrote 31744 bytes from file blinky.hex in 1.404485s (22.072 KiB/s)
** Programming Finished **
** Verify Started **
Error: checksum mismatch - attempting binary compare
verified 30672 bytes in 0.163494s (183.206 KiB/s)
** Verified OK **
** Resetting Target **
invalid subcommand "disable_wdog"
in procedure 'program' 
in procedure 'reset' called at file "embedded:startup.tcl", line 507
in procedure 'ocd_bouncer' 
in procedure 'ocd_process_reset' 
in procedure 'ocd_process_reset_inner' called at file "embedded:startup.tcl", line 248
in procedure 'kw01.cpu' called at file "embedded:startup.tcl", line 299
in procedure 'ocd_bouncer' 
in procedure 'kinetis'

shutdown command invoked


```

