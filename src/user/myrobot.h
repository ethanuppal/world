// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include "world/sim/robot.h"
#include "rpm_sensor.h"

class MyRobot final : public Robot {
    RPMSensor* rpm_sensor;
    std::vector<SensorInterface*> sensors_;

public:
    MyRobot();
    ~MyRobot();

    const std::vector<SensorInterface*>& sensors() const override;

    void update(double dtime) override;
};
