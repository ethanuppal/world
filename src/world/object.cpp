// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "object.h"

Object::Object(Geometry* geo, Texture* texture): geo(geo), texture(texture) {}

void Object::draw(SDL_Renderer* renderer, double ox, double oy) {
    texture->draw(renderer, geo, -ox, -oy);
}
