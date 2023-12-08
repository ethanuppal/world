// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include "world/object.h"
#include "world/scene.h"
#include "geo/circle.h"

class RobotObject : public Object {
    /** The x-coordinate of the robot's acceleration. */
    double ax;

    /** The y-coordinate of the robot's acceleration. */
    double ay;

    /** The x-coordinate of the robot's velocity. */
    double vx;

    /** The y-coordinate of the robot's acceleration. */
    double vy;

    Circle* pos();
    Circle* pos() const;

    void assert_inv(const Scene& scene);

    /** Stops the robot in its tracks immediately. */
    void stop();

    /** Triggers a collision mechanism. */
    void collide();

    /** Whether the robot is operating at a speed above its design capacity. */
    bool above_max_speed() const;

public:
    /* Constructs a new robot with the given location and color. */
    RobotObject(double x, double y, double size, uint8_t r, uint8_t g,
        uint8_t b, uint8_t a);

    /** Returns the x-coordinate of the center of the robot. */
    double center_x() const;

    /** Returns the y-coordinate of the center of the robot. */
    double center_y() const;

    double report_vx() const;
    double report_vy() const;

    /** Updates the robot in the `scene` after `dtime` has elapsed. */
    void update(Scene& scene, double dtime) override;

    /** Applies a force (`fx`, `fy`) to the robot. Assume the mass of the robot
     * is always 1. */
    void apply_force(double fx, double fy);
};
