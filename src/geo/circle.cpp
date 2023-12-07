// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "circle.h"

Circle::Circle(double x, double y, double r): x(x), y(y), r(r) {}

Geometry::Type Circle::type() const {
    return Geometry::Type::circle;
}
