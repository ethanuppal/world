// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include "geo/geometry.h"
#include "texture/texture.h"

class Object {
protected:
    Geometry* geo;
    Texture* texture;

public:
    /** Constructs a new object with geometry `geo` and texture `texture`. */
    Object(Geometry* geo, Texture* texture);

    /** Draws the object with the given `renderer` from the given origin (`ox`,
     * `oy`). */
    void draw(SDL_Renderer* renderer, double ox, double oy);
};
