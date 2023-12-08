// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "rpm_sensor.h"

#define RPM_SENSOR_RATE 100  // 0.1 seconds

RPMSensor::RPMSensor(): last(SDL_GetTicks64()) {}

bool RPMSensor::is_ready() {
    return SDL_GetTicks64() - last > RPM_SENSOR_RATE;
}

void RPMSensor::measure(RobotObject& robot, Scene& scene) {
    Uint64 now = SDL_GetTicks64();
    RPMData data;

    // really dumb way to add uncertainty
    // but the ticks are less accurate
    // and using this vx instead of last vx
    double dt = (double)(now - last) / 1000;
    data.dx = robot.report_vx() * dt;

    measurements.push_back(data);
    last = now;
}
