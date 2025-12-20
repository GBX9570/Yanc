bits 32

section .bss
stack_top:
    resb 131072
stack_end:

extern cmain

global _start

section .text
_start:
    mov esp, stack_end
    xor ebp, ebp
    call cmain
