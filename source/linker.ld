ENTRY(_start)

SECTIONS
{
    . = 2M;

    .boot :
    {
        *(.multiboot_header)
    }

    .text :
    {
        *(.text*)
        *(.rodata*)
    }

    .data :
    {
        *(.data*)
    }

    .bss :
    {
        *(.bss*)
        *(COMMON)
        . = ALIGN(4096);
    }
}
