// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include "gui/view.h"
#include "world/scene.h"

class WorldView final : public View {
    Scene* scene;

public:
    /** Creates a new world view visualizing `scene`. */
    WorldView(Scene* scene);
    ~WorldView() override;

    void on_event(SDL_Event event) override;
    void draw(SDL_Renderer* renderer, SDL_Rect frame) override;
};
