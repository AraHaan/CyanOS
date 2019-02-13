.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM


.section .text
.extern InitKernel
.extern CallCtors
.global loader


loader:
	mov $kernel_stack, %esp
	
	# commented out until I can fully get
	# long mode to work on x86_64 cpu's on a single OS build target.
	# mov %eax, 0x80000000    # Set the A-register to 0x80000000.
	# cpuid                  # CPU identification.
	# cmp %eax, 0x80000001    # Compare the A-register with 0x80000001.
	# jb .NoLongMode         # It is less, there is no long mode.
	
	call CallCtors
	
	push %eax
	push %ebx
	call InitKernel


# NoLongMode:
# 	


_stop:
	cli
	hlt
	jmp _stop


.section .bss
.space 2*1024*1024; # 2 MiB
kernel_stack:
