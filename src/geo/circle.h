// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "geometry.h"

struct Circle final : public Geometry {
    /** The x-coordinate of the center. */
    double x;

    /** The y-coordinate of the center. */
    double y;

    /** The radius. */
    double r;

    /** Constructs a new circle with the given dimensions (`x`, `y`, `r`). */
    Circle(double x, double y, double r);

    Geometry::Type type() const override;
};
