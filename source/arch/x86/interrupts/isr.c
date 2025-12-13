#include <x86/tty.h>
#include <tty/log.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void exceptionh(uint8_t vector);
void divison(void);
void debug(void);
void nmi(void);
void breakpoint(void);
void overflow(void);
void boundexceed();
void opcode();
void dna();
void doublefault();
void cso();
void badtss();
void badseg();
void ssf();
void gpf();
void pgf();
void reserved();
void x87();
void alc();
void macheck();
void simd();
void virtexc();
void cpe();

__attribute((noreturn))
void exceptionh(uint8_t vector) {
	switch(vector) {
		case (0):
			divison();
			break;
		case(1):
			debug();
			break;
		case(2):
			nmi();
			break;
		case(3):
			breakpoint();
			break;
		case(4):
			overflow();
			break;
		case(5):
			boundexceed();
			break;
		case(6):
			opcode();
			break;
		case(7):
			dna();
			break;
		case(8):
			doublefault();
			break;
		case(9):
			cso();
			break;
		case(10):
			badtss();
			break;
		case(11):
			badseg();
			break;
		case(12):
			ssf();
			break;
		case(13):
			gpf();
			break;
		case(14):
			pgf();
			break;
		case(15):
			reserved();
			break;
		case(16):
			x87();
			break;
		case(17):
			alc();
			break;
		case(18):
			macheck();
			break;
		case(19):
			simd();
			break;
		case(20):
			virtexc();
			break;
		case(21):
			cpe();
			break;
		case 22 ... 31:
			reserved();
			break;
		default:
			fatal("Unknown Exception!");
	}
	__builtin_unreachable();
}

__attribute__((noreturn))
void divison() {
    printk("Exception 0x00 Occurred #DE\n", 0x0F);
    fatal("Division Error");
    __builtin_unreachable();
}

__attribute__((noreturn))
void debug() {
	printk("Exception 0x01 Occurred #DB\n", 0x0F);
    fatal("Debug Exception");
    __builtin_unreachable();
}

__attribute__((noreturn))
void nmi() {
	printk("Exception 0x02 Occurred NMI\n", 0x0F);
    fatal("Non-Maskable Interrupt Exception");
    __builtin_unreachable();
}

__attribute__((noreturn))
void breakpoint() {
	printk("Exception 0x03 Occurred #BP\n", 0x0F);
    fatal("Breakpoint Exception");
    __builtin_unreachable();
}

__attribute__((noreturn))
void overflow() {
	printk("Exception 0x04 Occurred #OF\n", 0x0F);
    fatal("Overflow Exception");
    __builtin_unreachable();
}

__attribute__((noreturn))
void boundexceed() {
	printk("Exception 0x05 Occurred #BR\n", 0x0F);
    fatal("Bound Range Exceeded");
    __builtin_unreachable();
}

__attribute__((noreturn))
void opcode() {
	printk("Exception 0x06 Occurred #UD\n", 0x0F);
    fatal("Invalid Opcode");
    __builtin_unreachable();
}

__attribute__((noreturn))
void dna() {
	printk("Exception 0x07 Occurred #NM\n", 0x0F);
    fatal("Device Not Available");
    __builtin_unreachable();
}

__attribute__((noreturn))
void doublefault() {
	printk("Exception 0x08 Occurred #DF\n", 0x0F);
    fatal("Double Fault");
    __builtin_unreachable();
}

__attribute__((noreturn))
void cso() {
	printk("Exception 0x09 Occurred\n", 0x0F);
    fatal("Coprocessor Segment Overrun");
    __builtin_unreachable();
}

__attribute__((noreturn))
void badtss() {
	printk("Exception 0x0A Occurred #TS\n", 0x0F);
    fatal("Invalid TSS");
    __builtin_unreachable();
}

__attribute__((noreturn))
void badseg() {
	printk("Exception 0x0B Occurred #NP\n", 0x0F);
    fatal("Segment Not Present");
    __builtin_unreachable();
}

__attribute__((noreturn))
void ssf() {
	printk("Exception 0x0C Occurred #SS\n", 0x0F);
    fatal("Stack-Segment Fault");
    __builtin_unreachable();
}

__attribute__((noreturn))
void gpf() {
	printk("Exception 0x0D Occurred #GP\n", 0x0F);
    fatal("General Protection Fault");
    __builtin_unreachable();
}

__attribute__((noreturn))
void pgf() {
	printk("Exception 0x0E Occurred #PF\n", 0x0F);
    fatal("Page Fault");
    __builtin_unreachable();
}

__attribute__((noreturn))
void reserved() {
    fatal("Reserved");
    __builtin_unreachable();
}

__attribute__((noreturn))
void x87() {
	printk("Exception 0x10 Occurred #MF\n", 0x0F);
    fatal("x87 Floating Point Error");
    __builtin_unreachable();
}

__attribute__((noreturn))
void alc() {
	printk("Exception 0x11 Occurred #AC\n", 0x0F);
    fatal("Alignment Check");
    __builtin_unreachable();
}

__attribute__((noreturn))
void macheck() {
	printk("Exception 0x12 Occurred #MC\n", 0x0F);
    fatal("Machine Check");
    __builtin_unreachable();
}

__attribute__((noreturn))
void simd() {
	printk("Exception 0x13 Occurred #XM\n", 0x0F);
    fatal("SIMD Floating-Point Exception");
    __builtin_unreachable();
}

__attribute__((noreturn))
void virtexc() {
	printk("Exception 0x14 Occurred #VE\n", 0x0F);
    fatal("Virtualisation Esxception");
    __builtin_unreachable();
}

__attribute__((noreturn))
void cpe() {
	printk("Exception 0x15 Occurred #CP\n", 0x0F);
    fatal("Control Protection Exception");
    __builtin_unreachable();
}
