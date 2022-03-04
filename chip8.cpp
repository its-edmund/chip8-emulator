#include "chip8.h"
#include <stdlib.h>

void stack_push(short value) {
    if (sp == STACK_CAPACITY - 1) {
        return;
    }
    sp++;
    stack[sp] = value;
}

short stack_pop() {
    if (sp == -1) {
        return;
    }
    short return_value = stack[sp];
    sp--;
    return return_value;
}

short stack_peek() {
    if (sp == -1) {
        return;
    }
    return stack[sp];
}

void cycle() {
    opcode = memory[pc];

    char instruction = (opcode & 0xf000);

    switch (instruction) {
        case 0x0000:
            instruction = opcode & 0xf0ff;
            if (opcode == 0x0)
            break;
        case 0x1000:
            pc = opcode & 0x0fff;
            break;
        case 0x2000:
            stack_push(pc);
            pc = opcode & 0x0fff;
            break;
        case 0x3000:
            if (V[opcode & 0x0f00 >> 8] == (opcode & 0x00ff)) {
                pc += 2;
            }
            break;
        case 0x4000:
            if (V[opcode & 0x0f00 >> 8] != (opcode & 0x00ff)) {
                pc += 2;
            }
            break;
        case 0x5000:
            if (V[opcode & 0x0f00 >> 8] == V[opcode & 0x00f0 >> 4]) {
                pc += 2;
            }
            break;
        case 0x6000:
            V[opcode & 0x0f00 >> 8] = (opcode & 0x00ff);
            break;
        case 0x7000:
            V[opcode & 0x0f00 >> 8] = (opcode & 0x0f00 >> 8) + (opcode & 0x00ff);
            break;
        case 0x8000: // TODO
            break;
        case 0x9000:
            if ((opcode & 0x0f00 >> 8) != (opcode & 0x00f0 >> 4)) {
                pc += 2;
            }
            break;
        case 0xA000:
            I = (opcode & 0x0fff);
            break;
        case 0xB000:
            pc = (opcode & 0x0fff) + V[0];
            break;
        case 0xC000:
            char r = rand() % 255;
            V[opcode & 0x0f00 >> 8] = r & (opcode & 0x00ff);
            break;
        case 0xD000: // TODO
            break;
        case 0xE000: // TODO
            break;
        case 0xF000: // TODO
            break;
    }

    pc = pc + 2;
    if (delay_timer > 0) {
        delay_timer--;
    }
    if (sound_timer > 0) {
        sound_timer--;
        if (!sound_timer) {
            // Play sound
        }
    }
}

void parse_instruction() {

}