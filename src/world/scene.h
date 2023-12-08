// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include <vector>
#include <unordered_set>
#include "object.h"

class Scene {
    /** Represents a drawing layer for objects. */
    using LayerSet = std::unordered_set<Object*>;

    /** Objects in the background. */
    LayerSet background;

    /** Objects in the foreground. */
    LayerSet foreground;

    /** The x-coordinate of the origin. */
    double ox;

    /** The y-coordinate of the origin. */
    double oy;

public:
    /** The layer of an object. */
    enum class Layer { foreground, background };

    /** Constructs an empty scene centered at (0, 0). */
    Scene();

    /** The interactable object of the scene. */
    const std::unordered_set<Object*>& surroundings() const;

    /** Inserts a new `object` into the scene at the specified `layer`. */
    void add(Object* object, Layer layer);

    /** Moves an `object` in the scene to a new `layer`. */
    void change_layer(Object* object, Layer layer);

    /** Performs a scene-wide update, broadcasting that a time interval `dtime`
     * has elapsed. */
    void update(double dtime);

    /** Draws the scene in the given renderer. */
    void draw(SDL_Renderer* renderer);

    void set_origin(double ox, double oy);

    void translate(double dx, double dy);
};
