#include <x86/tty.h>

void ok(const char *s) {
    printk("[", 0x0F);
    printk("    OK    ", 0x02);
    printk("] ", 0x0F);
    printk(s, 0x0F);
    printk("\n", 0x00);
}

void fail(const char *s) {
    printk("[", 0x0F);
    printk("   FAIL   ", 0x0C);
    printk("] ", 0x0F);
    printk(s, 0x0F);
    printk("\n", 0x00);
}

void fatal_impl(const char *s, const char *file, int line) {
    printk("[", 0x0F);
    printk("   FATAL   ", 0x0C);
    printk("] Error: ", 0x0F);
    printk(s, 0x0F);
    printk("\nOccurred in: ", 0x08);
    printk(file, 0x07);
    printk("\n", 0x00);
    printk("It is now safe to turn off your computer.", 0x0C);
    __asm__ __volatile__("cli; hlt");
}

void warn(const char *s) {
    printk("[", 0x0F);
    printk("   FAIL   ", 0x0E);
    printk("] ", 0x0F);
    printk(s, 0x0F);
    printk("\n", 0x00);
}