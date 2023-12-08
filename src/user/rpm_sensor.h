// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include "world/sim/sensor.h"

struct RPMData {
    double dx;
    double dy;
};

class RPMSensor final : public Sensor<RPMData> {
    Uint64 last;

    void measure(RobotObject& robot, Scene& scene) override;

public:
    RPMSensor();

    bool is_ready() override;
};
