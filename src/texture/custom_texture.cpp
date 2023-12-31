// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "custom_texture.h"

CustomTexture::CustomTexture(Shader shader): shader(shader) {}

void CustomTexture::draw(SDL_Renderer* renderer, Geometry* geo, double dx,
    double dy) {
    shader(renderer, geo, dx, dy);
}
