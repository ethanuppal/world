// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include <functional>
#include "geo/geometry.h"

/** Adds color to objects. */
class Texture {
public:
    using Shader = std::function<void(SDL_Renderer*, Geometry*)>;

    /** Draw the texture with the specified geomety `geo` using `renderer`. */
    virtual void draw(SDL_Renderer* renderer, Geometry* geo) = 0;

    /** Creates a new texture with the given (`r`, `g`, `b`, `a`) color. */
    static Texture* create(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    /** Creates a new texture with a custom shader. */
    static Texture* create(Shader shader);
};
