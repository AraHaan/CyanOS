
# sudo apt-get install g++ binutils libc6-dev-i386
# sudo apt-get install VirtualBox grub-legacy xorriso

GCCPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

guiobjects = obj/GUIToolkit/Button.o \
			obj/GUIToolkit/CheckBox.o \
			obj/GUIToolkit/CheckBox.o \
			obj/GUIToolkit/Control.o \
			obj/GUIToolkit/DropDownBox.o \
			obj/GUIToolkit/Label.o \
			obj/GUIToolkit/ListBox.o \
			obj/GUIToolkit/Panel.o \
			obj/GUIToolkit/PictureBox.o \
			obj/GUIToolkit/ProgressBar.o \
			obj/GUIToolkit/RadioButton.o \
			obj/GUIToolkit/TextBox.o \
			obj/GUIToolkit/Theme.o \
			obj/GUIToolkit/Window.o \
			obj/GUIToolkit/WindowCommandButtons.o \
			obj/GUIToolkit/WindowFrame.o

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

obj/GUIToolkit/%.o: src/GUIToolkit/%.cpp
	gcc $(GCCPARAMS) -o $@ $<

cynkernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

libguitoolkit.so: linker.ld $(guiobjects)
	ld $(LDPARAMS) -T $< -o $@ $(guiobjects)

cynkernel.iso: cynkernel.bin libguitoolkit.so
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	mkdir iso/system
	cp $< iso/system/
	echo 'set timeout=0' >> iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "Cyanyde" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /system/cynkernel.bin' >> iso/boot/grub/grub.cfg
	echo '  boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso

install: cynkernel.bin
	sudo cp $< /boot/cynkernel.bin

.PHONY: clean
clean:
	rm -rf obj cynkernel.bin libguitoolkit.so cynkernel.iso
