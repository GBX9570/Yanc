#include <x86/tty.h>
#include <x86/gdt.h>
#include <tty/log.h>

void cmain(void) {
	printk("Welcome to ", 0x0F);
	printk("Yanc!\n", 0x0D);
	loadgdt();
	ok("GDT is loaded!");
	fatal("Nothing else to do.");
}
