// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include "gui/view.h"
#include "world/scene.h"
#include "util/keyboard.h"
#include "world/objects/robot_object.h"
#include "sim/simulator.h"

class WorldView final : public View {
    Scene* scene;
    Keyboard* keyboard;
    RobotObject* robot;
    Robot* user;
    Simulator* simulator;

    void setup();
    void update(double dtime);

public:
    /** Creates a new world view. */
    WorldView();
    ~WorldView() override;

    void on_event(const SDL_Event& event) override;
    void draw(SDL_Renderer* renderer, const SDL_Rect* frame,
        double dtime) override;
};
