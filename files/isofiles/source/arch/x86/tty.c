#include <stdint.h>
#include <stddef.h>

static int cursor = 0;
static uint8_t colour = 0x00;

void clear() {
	uint16_t* vga = (uint16_t*)0xB8000;
	int i = 0;
	cursor = 0;
	while(i < 2000) {
		vga[i] = (0x00 << 8) | ' ';
		i++;
	}
}

void mcursor(int x, int y) {
	cursor = y * 80 + x;
}

void setcolour(uint8_t fcolour) {
	colour = fcolour;
}

void putchar(char s) {

	if(cursor >= 2000) {
		clear();
	}
	
	if(s == '\n') {
		cursor = ((cursor / 80) + 1) * 80;
		return;
	}

	uint16_t* vga = (uint16_t*)0xB8000;
	vga[cursor] = (colour << 8) | s;
	cursor++;
}

void printk(const char* str, int fcolour) {
		colour = fcolour;

		int i = 0;
		while(str[i] != '\0') {
			putchar(str[i]);
			i++;
		}
}
