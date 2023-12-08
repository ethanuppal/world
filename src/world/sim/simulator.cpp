// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "simulator.h"

Simulator::Simulator(Scene* scene, RobotObject* robot_object, Robot* robot)
    : scene(scene), robot_object(robot_object), robot(robot) {}

Simulator::~Simulator() {
    delete scene;
    delete robot;
}

void Simulator::step(double dtime) {
    // update scene
    scene->update(dtime);

    // use sensors
    for (SensorInterface* sensor: robot->sensors()) {
        if (sensor->is_ready()) {
            sensor->measure(*robot_object, *scene);
        }
    }

    // update robot
    robot->update(dtime);
}
