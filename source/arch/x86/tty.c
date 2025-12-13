#include <stdint.h>
#include <stddef.h>

static int cursor = 0;

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

void printk(const char* str, int colour) {
	uint16_t* vga = (uint16_t*)0xB8000;
	int i = 0;
	while(str[i]) {
		if(cursor >= 2000) {
			clear();
		}

		if(str[i] == '\n') {
			cursor = ((cursor / 80) + 1) * 80;
			i++;
			continue;
		}
		
		vga[cursor] = (colour << 8) | str[i];
		i++;
		cursor++;
	}
}

