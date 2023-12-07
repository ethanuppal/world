// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "scene.h"

Scene::Scene(): ox(0), oy(0) {}

void Scene::add(Object* object, Layer layer) {
    switch (layer) {
        case Layer::background:
            background.insert(object);
            break;

        case Layer::foreground:
            foreground.insert(object);
            break;
    }
}

void Scene::change_layer(Object* object, Layer layer) {
    switch (layer) {
        case Layer::background:
            if (foreground.count(object)) {
                foreground.erase(object);
                background.insert(object);
            }
            break;

        case Layer::foreground:
            if (background.count(object)) {
                background.erase(object);
                foreground.insert(object);
            }
            break;
    }
}

void Scene::draw(SDL_Renderer* renderer) {
    for (Object* object: background) {
        object->draw(renderer, ox, oy);
    }
    for (Object* object: foreground) {
        object->draw(renderer, ox, oy);
    }
}

void Scene::set_origin(double ox, double oy) {
    this->ox = ox;
    this->oy = oy;
}

void Scene::translate(double dx, double dy) {
    this->ox += dx;
    this->oy += dy;
}
