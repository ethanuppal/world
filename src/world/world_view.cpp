// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "util/logger.h"
#include "world_view.h"

WorldView::WorldView(Scene* scene): scene(scene) {}
WorldView::~WorldView() {
    delete scene;
}

void WorldView::on_event(SDL_Event event) {}

void WorldView::draw(SDL_Renderer* renderer, SDL_Rect frame) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    scene->draw(renderer);
}
