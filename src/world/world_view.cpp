// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "util/logger.h"
#include "world_view.h"
#include "world.h"

#define FORCE 100

WorldView::WorldView()
    : scene(new Scene()),
      keyboard(new Keyboard()),
      robot(new RobotObject(0, 0, 50, 0, 255, 0, 255)) {
    setup();
}
WorldView::~WorldView() {
    delete scene;
    delete keyboard;
}

#define ENCL_W 400
#define ENCL_H 400
#define WALL_S 25

void WorldView::setup() {
    // add robot
    scene->add(robot, Scene::Layer::foreground);

    // mark play area
    scene->add(new Block(-ENCL_W / 2, -ENCL_H / 2, ENCL_W, ENCL_H, 255, 255,
                   255, 255),
        Scene::Layer::background);

    // add walls
    // left wall
    scene->add(new Block(-ENCL_W / 2 - WALL_S, -ENCL_H / 2 - WALL_S, WALL_S,
                   ENCL_H + WALL_S * 2, 255, 0, 0, 255),
        Scene::Layer::foreground);
    // right wall
    scene->add(new Block(ENCL_W / 2, -ENCL_H / 2 - WALL_S, WALL_S,
                   ENCL_H + WALL_S * 2, 255, 0, 0, 255),
        Scene::Layer::foreground);
    // top wall
    scene->add(new Block(-ENCL_W / 2, -ENCL_H / 2 - WALL_S, ENCL_W, WALL_S, 255,
                   0, 0, 255),
        Scene::Layer::foreground);
    // bottom wall
    scene->add(new Block(-ENCL_W / 2, ENCL_H / 2, ENCL_W, WALL_S, 255, 0, 0,
                   255),
        Scene::Layer::foreground);
}

void WorldView::update(double dtime) {
    double fx = 0;
    double fy = 0;

    if (keyboard->query(SDLK_UP)) {
        fy -= FORCE;
    }
    if (keyboard->query(SDLK_DOWN)) {
        fy += FORCE;
    }
    if (keyboard->query(SDLK_RIGHT)) {
        fx += FORCE;
    }
    if (keyboard->query(SDLK_LEFT)) {
        fx -= FORCE;
    }

    robot->apply_force(fx * dtime, fy * dtime);

    scene->update(dtime);
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
