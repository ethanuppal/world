// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "geometry.h"
#include "rect.h"
#include "circle.h"
#include "util/logger.h"

bool Geometry::rect_rect_overlaps_with(const Rect* rect1, const Rect* rect2) {
    return (rect1->min_x() <= rect2->max_x() && rect1->max_x() >= rect2->min_x()
            && rect1->min_y() <= rect2->max_y()
            && rect1->max_y() >= rect2->min_y());
}

bool Geometry::circle_circle_overlaps_with(const Circle* circle1,
    const Circle* circle2) {
    double dx = circle1->x - circle2->x;
    double dy = circle1->y - circle2->y;
    return dx * dx + dy * dy
           <= circle1->r * circle1->r + circle2->r * circle2->r;
}

// https://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection
bool Geometry::rect_circle_overlaps_with(const Rect* rect,
    const Circle* circle) {
    double mid_x = rect->x + rect->w / 2;
    double mid_y = rect->y + rect->h / 2;

    double circ_dx = abs(mid_x - circle->x);
    double circ_dy = abs(mid_y - circle->y);

    if (circ_dx > (rect->w / 2 + circle->r)) {
        return false;
    }
    if (circ_dy > (rect->h / 2 + circle->r)) {
        return false;
    }

    if (circ_dx <= (rect->w / 2)) {
        return true;
    }
    if (circ_dy <= (rect->h / 2)) {
        return true;
    }

    double corner_dx = (circ_dx - rect->w / 2);
    double corner_dy = (circ_dy - rect->h / 2);
    double corner_dist_sq = corner_dx * corner_dx + corner_dy * corner_dy;
    return corner_dist_sq <= circle->r * circle->r;
}

bool Geometry::geometries_overlap(const Geometry* geo1, const Geometry* geo2) {
    // verbose because of C++ casting and no pattern matching :(
    if (geo1->type() == Type::rect && geo2->type() == Type::rect) {
        // rect-rect
        const Rect* rect1 = static_cast<const Rect*>(geo1);
        const Rect* rect2 = static_cast<const Rect*>(geo2);
        return rect_rect_overlaps_with(rect1, rect2)
               || rect_rect_overlaps_with(rect2, rect1);
    } else if (geo1->type() == Type::circle && geo2->type() == Type::circle) {
        // circle-circle
        const Circle* circle1 = static_cast<const Circle*>(geo1);
        const Circle* circle2 = static_cast<const Circle*>(geo2);
        return circle_circle_overlaps_with(circle1, circle2);
    } else if (geo1->type() == Type::rect && geo2->type() == Type::circle) {
        // rect-circle
        const Rect* rect = static_cast<const Rect*>(geo1);
        const Circle* circle = static_cast<const Circle*>(geo2);
        return rect_circle_overlaps_with(rect, circle);
    } else if (geo1->type() == Type::circle && geo2->type() == Type::rect) {
        // rect-circle
        const Circle* circle = static_cast<const Circle*>(geo1);
        const Rect* rect = static_cast<const Rect*>(geo2);
        return rect_circle_overlaps_with(rect, circle);
    } else {
        Log << "unsupported geometry types\n";
        exit(1);
    }
}

bool Geometry::overlaps_with(const Geometry* geo) const {
    return Geometry::geometries_overlap(this, geo);
}

Geometry* Geometry::rect(double x, double y, double w, double h) {
    return new Rect(x, y, w, h);
}

Geometry* Geometry::circle(double x, double y, double r) {
    return new Circle(x, y, r);
}
