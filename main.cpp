#include <SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int arc, const char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "sdl initialization failed: " << SDL_GetError() << '\n';
    } else {
        SDL_CreateWindow("SDL2 Demo", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);

        SDL_Delay(5000);
    }

    return 0;
}
