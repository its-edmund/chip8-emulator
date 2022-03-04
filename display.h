#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *m_window_renderer;
SDL_Event event;

void init_display();
void destroy_display();

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 320