// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include "world/scene.h"
#include "world/objects/robot_object.h"

class SensorInterface {
    virtual void measure(RobotObject& robot, Scene& scene) = 0;

public:
    /** Returns whether the sensor is ready for a reading. */
    virtual bool is_ready() = 0;

    friend class Simulator;
};
