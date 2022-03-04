#ifndef CHIP8_H
#define CHIP8_H

#define WIDTH 64
#define HEIGHT 32
#define STACK_CAPACITY 16
#define MEMORY_CAPACITY 4096

extern unsigned char gfx[WIDTH*HEIGHT];
unsigned short opcode;
unsigned char memory[MEMORY_CAPACITY];
unsigned char V[16];
unsigned short I;
unsigned short pc;
unsigned char delay_timer;
unsigned char sound_timer;
unsigned short stack[STACK_CAPACITY];
unsigned short sp;

void stack_push(short value);
short stack_pop();
short stack_peek();

#endif