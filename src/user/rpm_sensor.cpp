// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "rpm_sensor.h"

#define RPM_SENSOR_RATE 100  // 0.1 seconds

RPMSensor::RPMSensor(): ticks(SDL_GetTicks64()) {}

bool RPMSensor::is_ready() {
    return SDL_GetTicks64() - ticks > RPM_SENSOR_RATE;
}

void RPMSensor::measure(RobotObject& robot, Scene& scene) {
    RPMData data;
    measurements.push_back(data);
    ticks = SDL_GetTicks64();
}
