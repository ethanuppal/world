// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include "geo/geometry.h"
#include "texture/texture.h"

class Scene;

class Object {
protected:
    Geometry* geo;
    Texture* texture;

public:
    /** Constructs a new object with geometry `geo` and texture `texture`. */
    Object(Geometry* geo, Texture* texture);

    bool collides_with(Object* object);

    /** Updates the object, which belongs to `scene`. */
    virtual void update(Scene& scene, double dtime);

    /** Draws the object with the given `renderer` from the given origin (`ox`,
     * `oy`). */
    void draw(SDL_Renderer* renderer, double ox, double oy);
};
