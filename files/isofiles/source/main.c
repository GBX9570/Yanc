#include <tty/printf.h>
#include <x86/tty.h>
#include <x86/gdt.h>
#include <tty/log.h>
#include <x86/interrupts/idt.h>
#include <tests/test.h>

void cmain(void) {
	setcolour(0x0F);
	printf("Welcome to ");
	setcolour(0x0D);
	printf("Yanc!\n");
	loadgdt();
	ok("GDT is loaded!");
	idt_init();
	ok("IDT is loaded!");
	div();
	fatal("Nothing else to do.");
}
