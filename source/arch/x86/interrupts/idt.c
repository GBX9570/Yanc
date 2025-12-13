#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t low; //
    uint16_t kcs;
    uint8_t  resv;
    uint8_t  attr;
    uint16_t high;
} __attribute__((packed)) entry;

// a struct declaring the gate descriptor

__attribute__((aligned(0x10)))
static entry idt[256]; // declare the gate descriptor struct as idt with a limit of 256 entries, aligned to 0x10

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idtr_s;
// holds the address of the exception handler and the limit

static idtr_s idtr;

void setdesc(uint8_t vector, void* isr, uint8_t flags);
void setdesc(uint8_t vector, void* isr, uint8_t flags) {
	entry* descriptor = &idt[vector];

	descriptor->low  = (uint32_t)isr & 0xFFFF; // sets low part of the descriptor
	descriptor->kcs  = 0x08; // tells the IDT where the kernel code segment is
	descriptor->attr = flags; // sets the attributes of the descriptor
	descriptor->high = (uint32_t)isr >> 16; // sets the high part of the descriptor
	descriptor->resv = 0; // sets reserved bits (presumably just to make CPU happy?)
}

static bool vectors[256];
extern void* isr_stub_table[];

void idt_init() {
	idtr.base = (uintptr_t)&idt[0]; // make the base a pointer to the first part of idt (which looks like it points to
	// low?? surely it should point to void* isr but what do i know
	idtr.limit = (uint16_t)sizeof(entry) * 256 - 1;
	// sets size of idt

	for(uint8_t vector = 0; vector < 32; vector++) {
		setdesc(vector, isr_stub_table[vector], 0x08E);
		vectors[vector] = true;
		// itterate through handlers till the right one is found (i think)
	}

	__asm__ volatile("lidt %0" : : "m"(idtr));
	__asm__ volatile("sti");
	// load the idt
}

// lord forgive me i have copied from the OSDev wiki
// i solemly swear i will repent

// it is my humble opinion that it isn't TOO bad reusing OSDev code so long as i actually understand the code
// to prove to myself that i do understand it i have commented the SHIT out of this

// cause like if i write this myself ill more or less end up with the same thing with slightly different names
