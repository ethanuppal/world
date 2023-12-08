// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "myrobot.h"

MyRobot::MyRobot(): rpm_sensor(new RPMSensor()) {
    sensors_.push_back(dynamic_cast<SensorInterface*>(rpm_sensor));
}

MyRobot::~MyRobot() {
    delete rpm_sensor;
}

const std::vector<SensorInterface*>& MyRobot::sensors() const {
    return sensors_;
}

void MyRobot::update(double dtime) {}
