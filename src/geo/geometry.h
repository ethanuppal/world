// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

struct Rect;
struct Circle;

/** The geometry of an object. Can be one of a limited types, see
 * `Geometry::Type`. */
class Geometry {
    /**
     * Returns whether the given rectangles overlap.
     */
    static bool rect_rect_overlaps_with(const Rect* rect1, const Rect* rect2);

    /**
     * Returns whether the given circles overlap.
     */
    static bool circle_circle_overlaps_with(const Circle* circle1,
        const Circle* circle2);

    /** Returns whether the given rectangle and circle overlap. */
    static bool rect_circle_overlaps_with(const Rect* rect,
        const Circle* circle);

    /** Returns whether `geo1` and `geo2` overlap. */
    static bool geometries_overlap(const Geometry* geo1, const Geometry* geo2);

public:
    /** A type of object geometry. */
    enum class Type { rect, circle };

    virtual ~Geometry() = default;

    /**
     * The type of goemetry.
     */
    virtual Type type() const = 0;

    /**
     * Whether this geometry overlaps with the one given by `geo`.
     */
    virtual bool overlaps_with(const Geometry* geo) const;

    /**
     * Creates a new rectangle geometry.
     *
     * @param x The x-coordinate of the upper-left corner.
     * @param y The y-coordinate of the upper-left corner,
     * @param w The width of the rectangle.
     * @param h The height of the rectangle.
     */
    static Geometry* rect(double x, double y, double w, double h);

    /**
     * Creates a new circle geometry.
     *
     * @param x The x-coordinate of the center.
     * @param y The y-coordinate of the center,
     * @param w The radius of the circle.
     */
    static Geometry* circle(double x, double y, double r);
};
