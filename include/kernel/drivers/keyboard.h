
#ifndef KERNEL_KEYBOARD_H
#define KERNEL_KEYBOARD_H

class KeyboardEventHandler
{
public:
	KeyboardEventHandler();

	virtual void OnKeyDown(char);
	virtual void OnKeyUp(char);
};

class KeyboardDriver : public InterruptHandler, public Driver
{
	Port8Bit dataport;
	Port8Bit commandport;

	KeyboardEventHandler* handler;
public:
	KeyboardDriver(InterruptManager* manager, KeyboardEventHandler *handler);
	~KeyboardDriver();
	virtual uint32_t HandleInterrupt(uint32_t esp);
	virtual void Activate();
};

#endif
