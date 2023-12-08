// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "world/object.h"
#include "world/scene.h"

class Robot : public Object {
public:
    /* Constructs a new robot with the given location and color. */
    Robot(double x, double y, double size, uint8_t r, uint8_t g, uint8_t b,
        uint8_t a);

    /** Returns the x-coordinate of the center of the robot. */
    double center_x() const;

    /** Returns the y-coordinate of the center of the robot. */
    double center_y() const;

    /** Attempts to move by (`dx`, `dy`) in `scene`. */
    void attempt_move(double dx, double dy, const Scene& scene);
};
