#include <SDL2/SDL.h>
#include <iostream>
#include "display.h"
#include "chip8.h"

void init_display() {
    window = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized: ";
    } else {
        std::cout << "SDL video system is ready to go\n";
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0 );
        if( window == NULL )
        {
            std::cout << "Window could not be created! SDL_Error: %s\n", SDL_GetError();
        }
        else
        {
            m_window_renderer = NULL;
            m_window_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


            SDL_Rect rect;
            rect.x = 100;
            rect.y = 100;
            rect.w = 10;
            rect.h = 10;

            SDL_SetRenderDrawColor(m_window_renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(m_window_renderer, &rect);

            SDL_RenderPresent(m_window_renderer);

            SDL_SetRenderDrawColor(m_window_renderer, 0, 0, 255, 255);
        }
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();
}

void destroy_display() {
    std::cout << "Quitting...\n";
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void display_blank() {
      // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       1000, 1000, 0);
}