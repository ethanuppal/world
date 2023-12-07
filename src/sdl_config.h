// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include <cstddef>
#include <SDL.h>
#include "logger.h"

/** A wrapper around SDL windows and rendering. */
class SDLConfig {
    /** The width of the window. */
    size_t width;

    /** The height of the window. */
    size_t height;

    /** The SDL window. */
    SDL_Window* window;

    /** The renderer for the window. */
    SDL_Renderer* renderer;

public:
    /** Initializes SDL and constructs a new window with the given `name`,
     * `width`, and `height`.
     *
     * @param name The name of the window.
     */
    SDLConfig(std::string name, size_t width, size_t height)
        : width(width), height(height) {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            Log << "SDL initialization failed: " << SDL_GetError() << '\n';
            exit(1);
        }

        window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        if (!window) {
            Log << "failed to create window: " << SDL_GetError() << '\n';
            exit(1);
        }
    }

    ~SDLConfig() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }

    /** Invokes `SDL_Delay` with the given milliseconds delay `ms`. */
    void delay(uint32_t ms) {
        SDL_Delay((Uint32)ms);
    }
};
