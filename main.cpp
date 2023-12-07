#include <iostream>
#include "sdl_config.h"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

int main() {
    SDLConfig sdl_config("My Window", WINDOW_WIDTH, WINDOW_HEIGHT);
    sdl_config.event_loop();
}
