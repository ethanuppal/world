// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include "texture.h"

/** Draws an object with a custom texture. */
class CustomTexture final : public Texture {
    Shader shader;

public:
    CustomTexture(Shader shader);

    void draw(SDL_Renderer* renderer, Geometry* geo) override;
};
