// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include <vector>
#include <set>
#include "object.h"

class Scene {
    using LayerSet = std::unordered_set<Object*>;

    LayerSet foreground;
    LayerSet background;

public:
    /** The layer of an object. */
    enum class Layer { foreground, background };

    /** Constructs an empty scene. */
    Scene();

    /** Inserts a new `object` into the scene at the specified `layer`. */
    void add(Object* object, Layer layer);

    /** Moves an `object` in the scene to a new `layer`. */
    void change_layer(Object* object, Layer layer);

    /** Draws the scene in the given renderer. */
    void draw(SDL_Renderer* renderer);
};
