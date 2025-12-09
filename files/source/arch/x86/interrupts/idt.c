#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint16_t low;
    uint16_t kcs;
    uint8_t  resv;
    uint8_t  attr;
    uint16_t high;
} __attribute__((packed)) entry;

__attribute__((aligned(0x10)))
static entry idt[256];

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idtr_s;

static idtr_s idtr;

// lord forgive me i have copied from the OSDev wiki
// i solemly swear i will repent

