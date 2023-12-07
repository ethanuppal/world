// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "world/object.h"

class Block : public Object {
public:
    /* Constructs a new block with the given location and color. */
    Block(double x, double y, double w, double h, uint8_t r, uint8_t g,
        uint8_t b, uint8_t a);
};
