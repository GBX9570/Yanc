#ifndef TTY_H
#define TTY_H

#include <stdint.h>
#include <stddef.h>

void clear();
void printk(const char* str, int fcolour);
void mcursor(int x, int y);
void putchar(const char s);
void setcolour(uint8_t fcolour);

#endif
