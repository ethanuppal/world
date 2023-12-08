// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include <cassert>
#include <iostream>
#include "robot_object.h"

#define FRICTION(v, a) ((v) * 0.9)
#define MAX_SPEED 200
#define COLLISION_LOSS 0.2 /* how elastic do we want!! */

RobotObject::RobotObject(double x, double y, double size, uint8_t r, uint8_t g,
    uint8_t b, uint8_t a)
    : Object(Geometry::circle(x, y, size / 2), Texture::mono(r, g, b, a)),
      ax(0),
      ay(0),
      vx(0),
      vy(0) {}

Circle* RobotObject::pos() {
    return static_cast<Circle*>(this->geo);
}

Circle* RobotObject::pos() const {
    return static_cast<Circle*>(this->geo);
}

void RobotObject::assert_inv(const Scene& scene) {
#ifndef RELEASE_BUILD
    for (Object* object: scene.surroundings()) {
        if (this != object) {
            assert(!collides_with(object));
        }
    }
#endif
}

double RobotObject::center_x() const {
    return pos()->x;
}

double RobotObject::center_y() const {
    return pos()->y;
}

double RobotObject::report_vx() const {
    return vx;
}

double RobotObject::report_vy() const {
    return vy;
}

void RobotObject::update(Scene& scene, double dtime) {
    assert_inv(scene);

    vx += ax * dtime;
    vy += ay * dtime;
    if (above_max_speed()) {
        double angle = atan2(vy, vx);
        vx = MAX_SPEED * cos(angle);
        vy = MAX_SPEED * sin(angle);
    }

    double old_x = pos()->x;
    double old_y = pos()->y;
    pos()->x += vx * dtime;
    pos()->y += vy * dtime;
    for (Object* object: scene.surroundings()) {
        if (this != object && collides_with(object)) {
            pos()->x = old_x;
            pos()->y = old_y;
            collide();
            return;
        }
    }

    vx -= FRICTION(vx, ax) * dtime;
    vy -= FRICTION(vy, ay) * dtime;
}

void RobotObject::apply_force(double fx, double fy) {
    ax += fx;
    ay += fy;
}

void RobotObject::stop() {
    ax = 0;
    ay = 0;
    vx = 0;
    vy = 0;
}

void RobotObject::collide() {
    vx = -COLLISION_LOSS * vx;
    vy = -COLLISION_LOSS * vy;
    ax = 0;
    ay = 0;
}

bool RobotObject::above_max_speed() const {
    return vx * vx + vy * vy > MAX_SPEED * MAX_SPEED;
}
