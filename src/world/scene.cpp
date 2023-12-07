// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "scene.h"

Scene::Scene() {}

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
            if (foreground.contains(object)) {
                foreground.erase(object);
                background.insert(object);
            }
            break;

        case Layer::foreground:
            if (background.contains(object)) {
                background.erase(object);
                foreground.insert(object);
            }
            break;
    }
}

void Scene::draw(SDL_Renderer* renderer) {
    for (Object* object: background) {
        object->draw(renderer);
    }
    for (Object* object: foreground) {
        object->draw(renderer);
    }
}
