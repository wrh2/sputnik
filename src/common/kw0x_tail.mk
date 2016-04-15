
COBJS =  $(DRIVER_COBJS) $(XPROJ).o
all: $(XPROJ)

$(XPROJ): $(COBJS) $(COMM_COBJS)
	@echo "-------- LINKING $@ "
	@$(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.s: %.c
	@echo "-------- COMPILING $@ "
	@$(CC) $(CPPFLAGS) $(CFLAGS) -S $^ -o $@

%.o: %.s
	@echo "-------- COMPILING $@ "
	@$(AS) $^ -o $@

%.hex: %
	@echo "-------- CREATE HEX FILE $@ "
	@$(ARCH)-objcopy -O ihex $^ $@

write: $(XPROJ).hex
	@echo "-------- SEND HEX FILE TO FLASH"
	@openocd -s $(OPENOCD_DIR) -f $(OOCD_CFG) -c "program $^ verify reset exit"

gdb: $(XPROJ)
	@echo "-------- STARTING GDB"
	@$(ARCH)-gdb -q $^ -x $(GDB_CFG)

clean:
	$(RM) $(XPROJ) *.o *.hex *.s ../drivers/*.s ../drivers/*.o ../common/*.o

rebuild: clean
	$(MAKE)
