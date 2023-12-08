// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <vector>
#include "sensor_interface.h"

/** An abstract robot to embed in the simulation. */
class Robot {
public:
    /** Retrieves the sensors of the robot. */
    virtual const std::vector<SensorInterface*>& sensors() const = 0;

    /** Runs the software of the robot. */
    virtual void update() = 0;
};
