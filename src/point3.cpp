#include "point3.hpp"

float dot(Point3 a, Point3 b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Point3 cross(Point3 a, Point3 b) {
    Point3 c((a.y*b.z - a.z*b.y), (a.x*b.z - a.z*b.x), (a.x*b.y - a.y*b.x));
    return c;
}
