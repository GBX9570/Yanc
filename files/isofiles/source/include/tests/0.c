#include <tty/printf.h>
#include <x86/tty.h>

void div() {
    printf("Running divison by zero test!\n");
    __asm__ volatile("int $0");
}
