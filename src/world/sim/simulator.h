// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include "world/scene.h"
#include "world/objects/robot_object.h"
#include "world/sim/robot.h"

class Simulator {
    Scene* scene;
    RobotObject* robot_object;
    Robot* robot;

public:
    /**
     * Constructs a new robot simulator.
     *
     * @param scene The world to simulate the robot in.
     * @param robot_object The object corresponding to the simulated robot.
     * @param robot The user abstraction to the robot.
     */
    Simulator(Scene* scene, RobotObject* robot_object, Robot* robot);

    ~Simulator();

    /**
     * Performs one step of the simulation.
     */
    void step(double dtime);
};
