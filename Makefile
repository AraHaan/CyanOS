
# sudo apt-get install g++ binutils libc6-dev-i386
# sudo apt-get install VirtualBox grub-legacy xorriso

GCCPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = obj/kernel/loader.o \
		obj/kernel/gdt.o \
		obj/kernel/drivers/driver.o \
		obj/kernel/hardwarecommunication/port.o \
		obj/kernel/hardwarecommunication/interruptstubs.o \
		obj/kernel/hardwarecommunication/interrupts.o \
		obj/kernel/hardwarecommunication/pci.o \
		obj/kernel/drivers/keyboard.o \
		obj/kernel/drivers/mouse.o \
		obj/kernel/kernel.o

run: cynkernel.iso
	(killall VirtualBox && sleep 1) || true
	VirtualBox --startvm "Cyanyde" &

obj/kernel/%.o: src/kernel/%.cpp
	gcc $(GCCPARAMS) -c -o $@ $<

obj/kernel/%.o: src/kernel/%.s
	as $(ASPARAMS) -o $@ $<

cynkernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

cynkernel.iso: cynkernel.bin
	mkdir iso
	mkdir iso/boot/
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=0' >> iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "Cyanyde" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/cynkernel.bin' >> iso/boot/grub/grub.cfg
	echo '  boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso

install: cynkernel.bin
	sudo cp $< /boot/cynkernel.bin

.PHONY: clean
clean:
	rm -rf obj cynkernel.bin cynkernel.iso
