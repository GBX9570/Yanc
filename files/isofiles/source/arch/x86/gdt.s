BITS 32

gdts:
    ; null descriptor
        dd 0x0
        dd 0x0
    
    ; kernel code desc
        dw 0xffff
        dw 0x0
        db 0x0
        db 0b10011010
        db 0b11001111
        db 0x0
    
    ; kernel data desc
        dw 0xffff
        dw 0x0
        db 0x0
        db 0b10010010
        db 0b11001111
        db 0x0
gdte:

gdtd:
    dw gdte - gdts - 1
    dd gdts


global gdtf

gdtf:
    lgdt[gdtd]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush
flush:
    ret