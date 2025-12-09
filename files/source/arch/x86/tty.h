#ifndef TTY_H
#define TTY_H

void clear();
void printk(const char* str, int colour);
void mcursor(int x, int y);
void putchar(char character);

#endif
