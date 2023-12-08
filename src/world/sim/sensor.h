// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <deque>
#include "sensor_interface.h"

/** A sensor for the outside world. */
template<typename T>
class Sensor : public SensorInterface {
    virtual void measure(RobotObject& robot, Scene& scene) = 0;

protected:
    std::deque<T> measurements;

public:
    virtual bool is_ready() = 0;

    /** Requests a reading from the sensor. Can block until a reading is
     * available. */
    T read();

    friend class Simulator;
};
