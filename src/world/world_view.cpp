// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "util/logger.h"
#include "world_view.h"
#include "world.h"

#define SPEED 20

WorldView::WorldView()
    : scene(new Scene()),
      keyboard(new Keyboard()),
      robot(new Robot(0, 0, 50, 0, 255, 0, 255)) {
    setup();
}
WorldView::~WorldView() {
    delete scene;
    delete keyboard;
}

void WorldView::setup() {
    scene->add(new Block(0, 0, 50, 50, 255, 0, 0, 255),
        Scene::Layer::background);
    scene->add(robot, Scene::Layer::foreground);
}

void WorldView::update(double dtime) {
    double dx = 0;
    double dy = 0;

    if (keyboard->query(SDLK_UP)) {
        dy -= SPEED;
    }
    if (keyboard->query(SDLK_DOWN)) {
        dy += SPEED;
    }
    if (keyboard->query(SDLK_RIGHT)) {
        dx += SPEED;
    }
    if (keyboard->query(SDLK_LEFT)) {
        dx -= SPEED;
    }

    dx *= dtime;
    dy *= dtime;

    robot->attempt_move(dx, dy, *scene);
}

void WorldView::on_event(const SDL_Event& event) {
    keyboard->update(event);
}

void WorldView::draw(SDL_Renderer* renderer, const SDL_Rect* frame,
    double dtime) {
    // update scene
    update(dtime);

    // center robot on screen
    scene->set_origin(robot->center_x() - frame->w / 2,
        robot->center_y() - frame->h / 2);

    // draw scene
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    scene->draw(renderer);
}
