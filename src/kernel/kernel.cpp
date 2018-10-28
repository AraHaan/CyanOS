/*
 * kernel.cpp
 * Cyanyde OS kernel code file.
 * This file implements most or parts of the kernel.
 */
#define WITH_KERNEL
#define KERNEL_BUILD
#include "../../include/Cyanyde.h"

// TODO: Write everything.

void k_printf(int8_t* str)
{
	static uint16_t* VideoMemory = (uint16_t*)0xb8000;

	static uint8_t x = 0, y = 0;

	for (int32_t i = 0; str[i] != '\0'; ++i)
	{
		switch (str[i])
		{
			case '\n':
				x = 0;
				y++;
				break;
			default:
				VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
				x++;
				break;
		}

		if(x >= 80)
		{
			x = 0;
			y++;
		}

		if(y >= 25)
		{
			for(y = 0; y < 25; y++)
			{
				for(x = 0; x < 80; x++)
				{
					VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
				}
			}
			x = 0;
			y = 0;
		}
	}
}

void k_printfHex(uint8_t key)
{
    char* foo = "00";
    char* hex = "0123456789ABCDEF";
    foo[0] = hex[(key >> 4) & 0xF];
    foo[1] = hex[key & 0xF];
    k_printf(foo);
}

class PrintfKeyboardEventHandler : public KeyboardEventHandler
{
public:
    void OnKeyDown(char c)
    {
        char* foo = " ";
        foo[0] = c;
        k_printf(foo);
    }
};

class MouseToConsole : public MouseEventHandler
{
    int8_t x, y;
public:

    MouseToConsole()
    {
    }

    virtual void OnActivate()
    {
        uint16_t* VideoMemory = (uint16_t*)0xb8000;
        x = 40;
        y = 12;
        VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                            | (VideoMemory[80*y+x] & 0xF000) >> 4
                            | (VideoMemory[80*y+x] & 0x00FF);
    }

    virtual void OnMouseMove(int xoffset, int yoffset)
    {
        static uint16_t* VideoMemory = (uint16_t*)0xb8000;
        VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                            | (VideoMemory[80*y+x] & 0xF000) >> 4
                            | (VideoMemory[80*y+x] & 0x00FF);

        x += xoffset;
        if(x >= 80) x = 79;
        if(x < 0) x = 0;
        y += yoffset;
        if(y >= 25) y = 24;
        if(y < 0) y = 0;

        VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                            | (VideoMemory[80*y+x] & 0xF000) >> 4
                            | (VideoMemory[80*y+x] & 0x00FF);
    }

};

typedef void (*constructor)();
KEXTERN constructor start_ctors;
KEXTERN constructor end_ctors;

KEXTERN void CallCtors()
{
	for(constructor* i = &start_ctors; i != &end_ctors; i++)
	{
		(*i)();
	}
}


KEXTERN void InitKernel(const void* multiboot_structure, uint32_t magicnumber)
{
	k_printf("Welcome to Cyanyde, a free an open source operating system.\n");
	k_printf("-----------------------------------------------------------\n");
	k_printf("Initializing Global Descriptor Table...\n");
	GlobalDescriptorTable gdt;
	InterruptManager interrupts(0x20, &gdt);
	k_printf("Global Descriptor Table initialized.\n");
	k_printf("Initializing Hardware, Stage 1\n");

	DriverManager drvManager;

	PrintfKeyboardEventHandler kbhandler;
	KeyboardDriver keyboard(&interrupts, &kbhandler);
	drvManager.AddDriver(&keyboard);

	MouseToConsole mousehandler;
	MouseDriver mouse(&interrupts, &mousehandler);
	drvManager.AddDriver(&mouse);

	PeripheralComponentInterconnectController PCIController;
	PCIController.SelectDrivers(&drvManager, &interrupts);

	k_printf("Initializing Hardware, Stage 2\n");
	drvManager.ActivateAll();
	k_printf("Initializing Hardware, Stage 3\n");
	while (1);
}
