// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>

class View {
public:
    virtual ~View() = default;

    /** Handle a new `event`. */
    virtual void on_event(SDL_Event event) = 0;

    /** Draw the view's contents to `renderer`. */
    virtual void draw(SDL_Renderer* renderer, SDL_Rect frame) = 0;
};
