// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "robot.h"
#include "geo/circle.h"

Robot::Robot(double x, double y, double size, uint8_t r, uint8_t g, uint8_t b,
    uint8_t a)
    : Object(Geometry::circle(x, y, size / 2), Texture::mono(r, g, b, a)) {}

double Robot::center_x() const {
    return static_cast<Circle*>(this->geo)->x;
}

double Robot::center_y() const {
    return static_cast<Circle*>(this->geo)->y;
}

void Robot::attempt_move(double dx, double dy, const Scene& scene) {
    Circle* circle = static_cast<Circle*>(this->geo);
    circle->x += dx;
    circle->y += dy;
}
