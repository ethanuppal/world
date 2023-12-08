// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "object.h"

Object::Object(Geometry* geo, Texture* texture): geo(geo), texture(texture) {}

bool Object::collides_with(Object* object) {
    return geo->overlaps_with(object->geo);
}

void Object::update(Scene& scene, double dtime) {}

void Object::draw(SDL_Renderer* renderer, double ox, double oy) {
    texture->draw(renderer, geo, -ox, -oy);
}
