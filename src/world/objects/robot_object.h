// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include "world/object.h"
#include "world/scene.h"
#include "geo/circle.h"

class RobotObject : public Object {
    double ax;
    double ay;
    double vx;
    double vy;

    Circle* pos();
    Circle* pos() const;

    void assert_inv(const Scene& scene);

public:
    /* Constructs a new robot with the given location and color. */
    RobotObject(double x, double y, double size, uint8_t r, uint8_t g,
        uint8_t b, uint8_t a);

    /** Returns the x-coordinate of the center of the robot. */
    double center_x() const;

    /** Returns the y-coordinate of the center of the robot. */
    double center_y() const;

    void update(Scene& scene, double dtime) override;

    /** Applies a force (`fx`, `fy`) to the robot. Assume the mass of the robot
     * is always 1. */
    void apply_force(double fx, double fy);

    /** Stops the robot in its tracks immediately. */
    void stop();

    void collide();

    /** Whether the robot is operating at a speed above its design capacity. */
    bool above_max_speed() const;
};
