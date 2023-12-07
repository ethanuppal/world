// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <functional>
#include "texture.h"

/** Draws an object with a single color. */
class MonoTexture final : public Texture {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

public:
    MonoTexture(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    void draw(SDL_Renderer* renderer, Geometry* geo, double dx,
        double dy) override;
};
