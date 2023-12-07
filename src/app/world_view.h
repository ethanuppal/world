// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include "gui/view.h"

class WorldView final : public View {
public:
    WorldView();
    ~WorldView() override;

    void on_event(SDL_Event event) override;
    void draw(SDL_Renderer* renderer, SDL_Rect frame) override;
};
