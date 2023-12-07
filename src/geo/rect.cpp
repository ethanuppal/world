// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "rect.h"

Rect::Rect(double x, double y, double w, double h): x(x), y(y), w(w), h(h) {}

Geometry::Type Rect::type() const {
    return Geometry::Type::rect;
}

double Rect::min_x() const {
    return x;
}

double Rect::min_y() const {
    return y;
}

double Rect::max_x() const {
    return x + w;
}

double Rect::max_y() const {
    return y + h;
}
