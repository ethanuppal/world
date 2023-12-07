// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "util/logger.h"
#include "world_view.h"

WorldView::WorldView() {}
WorldView::~WorldView() {}

void WorldView::on_event(SDL_Event event) {}

void WorldView::draw(SDL_Renderer* renderer, SDL_Rect frame) {
    Uint8 r = 255, g = 0, b = 0, a = SDL_ALPHA_OPAQUE;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    // outline rect
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawRect(renderer, &frame);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    // fill up rectangle with color
    SDL_RenderFillRect(renderer, &frame);
}
