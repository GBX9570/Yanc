#include <x86/tty.h>

__attribute__((noreturn))
void exceptionh() {
    
    __asm__ volatile("cli; hlt");
}