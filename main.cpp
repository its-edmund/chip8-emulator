#include <iostream>
#include <SDL2/SDL.h>
#include "display.h"

int main(int argc, char *argv[]) {
    bool is_running = true;
    init_display();
    while (is_running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }
        SDL_Delay(16);
    }
    destroy_display();
    return 0;
}