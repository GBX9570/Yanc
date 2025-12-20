#include <x86/tty.h>
#include <tty/printf.h>

void ok(const char *s) {
    setcolour(0x0F);
    printf("[");
    setcolour(0x02);
    printf("    OK    ");
    setcolour(0x0F);
    printf("] %s\n", s);
}

void fail(const char *s) {
    setcolour(0x0F);
    printf("[");
    setcolour(0x0C);
    printf("   FAIL   ");
    setcolour(0x0F);
    printf("] %s\n", s);
}

void fatal_impl(const char *s, const char *file, int line) {
    setcolour(0x0F);
    printf("[");
    setcolour(0x0C);
    printf("   FATAL   ");
    setcolour(0x0F);
    printf("] Error: %s\n", s);
    setcolour(0x07);
    printf("Occurred in: %s at line %d\n", file, line);
    setcolour(0x0C);
    printf("It is now safe to turn off your computer.");
    __asm__ __volatile__("cli; hlt");
}

void warn(const char *s) {
    setcolour(0x0F);
    printf("[");
    setcolour(0x0E);
    printf("   WARN   ");
    setcolour(0x0F);
    printf("] %s\n", s);
}
