// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "block.h"

Block::Block(double x, double y, double w, double h, uint8_t r, uint8_t g,
    uint8_t b, uint8_t a)
    : Object(Geometry::rect(x, y, w, h), Texture::mono(r, g, b, a)) {}
