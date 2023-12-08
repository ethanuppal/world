// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "mono_texture.h"
#include "geo/rect.h"
#include "geo/circle.h"

MonoTexture::MonoTexture(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r(r), g(g), b(b), a(a) {}

void MonoTexture::draw(SDL_Renderer* renderer, Geometry* geo, double dx,
    double dy) {
    switch (geo->type()) {
        case Geometry::Type::rect: {
            Rect* rect = static_cast<Rect*>(geo);
            SDL_Rect sdl_rect;
            sdl_rect.x = rect->x + dx;
            sdl_rect.y = rect->y + dy;
            sdl_rect.w = rect->w;
            sdl_rect.h = rect->h;

            SDL_SetRenderDrawColor(renderer, r, g, b, a);
            SDL_RenderDrawRect(renderer, &sdl_rect);
            SDL_SetRenderDrawColor(renderer, r, g, b, a);
            SDL_RenderFillRect(renderer, &sdl_rect);
            break;
        }
        case Geometry::Type::circle: {
            Circle* circle = static_cast<Circle*>(geo);

            // really bad circle algorithm
            // TODO: modular this out into a reusable circle drawer in case it's
            // needed elsewhere

            int min_y = (int)(circle->y - circle->r);
            int max_y = (int)(circle->y + circle->r);

            SDL_SetRenderDrawColor(renderer, r, g, b, a);
            int disty = -(int)circle->r;
            for (int y = min_y; y <= max_y; y++) {
                int xdist = (int)sqrt(circle->r * circle->r - disty * disty);
                int x1 = circle->x - xdist + dx;
                int x2 = circle->x + xdist + dx;
                SDL_RenderDrawLine(renderer, x1, y + dy, x2, y + dy);
                disty++;
            }

            break;
        }
    }
}
