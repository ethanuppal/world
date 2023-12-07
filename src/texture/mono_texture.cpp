// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "mono_texture.h"
#include "geo/rect.h"
#include "geo/circle.h"

MonoTexture::MonoTexture(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r(r), g(g), b(b), a(a) {}

void MonoTexture::draw(SDL_Renderer* renderer, Geometry* geo) {
    if (geo->type() == Geometry::Type::rect) {
        Rect* rect = static_cast<Rect*>(geo);
        SDL_Rect sdl_rect;
        sdl_rect.x = rect->x;
        sdl_rect.y = rect->y;
        sdl_rect.w = rect->w;
        sdl_rect.h = rect->h;

        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        SDL_RenderDrawRect(renderer, &sdl_rect);
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        SDL_RenderFillRect(renderer, &sdl_rect);
    }
}
