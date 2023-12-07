// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "geometry.h"

struct Rect final : public Geometry {
    /** The x-coordinate of the upper-left corner. */
    double x;

    /** The y-coordinate of the upper-left corner. */
    double y;

    /** The width. */
    double w;

    /** The height. */
    double h;

    /** Constructs a new rectangle with the given dimensions (`x`, `y`, `w`,
     * `h`). */
    Rect(double x, double y, double w, double h);

    Geometry::Type type() const override;

    /** Returns the x-coordinate of the upper-left corner. */
    double min_x() const;

    /** Returns the y-coordinate of the upper-left corner. */
    double min_y() const;

    /** Returns the x-coordinate of the lower-right corner. */
    double max_x() const;

    /** Returns the y-coordinate of the lower-right corner. */
    double max_y() const;
};
