// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "texture.h"
#include "custom_texture.h"
#include "mono_texture.h"

Texture* Texture::create(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return new MonoTexture(r, g, b, a);
}

Texture* Texture::create(Shader shader) {
    return new CustomTexture(shader);
}
