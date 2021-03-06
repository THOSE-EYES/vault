bits 32

section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002            ;x86_64 BIOS magic number
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum. m+f+c should be zero

global start			;program entry point
extern kmain	        ;kmain is defined in the c file

start:
  cli 					;block interrupts
  mov esp, stack_space	;set stack pointer
  call kmain			;call the C function
  hlt		 			;halt the CPU

section .bss
resb 8192				;8KB for stack
stack_space: