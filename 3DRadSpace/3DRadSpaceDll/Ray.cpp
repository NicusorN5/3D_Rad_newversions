#include "pch.h"
#include "Ray.h"

//https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
_3DRadSpaceDll::Vector3* _3DRadSpaceDll::Ray::IntersectsTriangle(const Triangle& triangle)
{
    Vector3* ret = nullptr;
    Vector3 rayOrigin = Position;
    Vector3 rayVector = Direction;
    const float EPSILON = 0.0000001f;
    Vector3 vertex0 = triangle.Point1;
    Vector3 vertex1 = triangle.Point2;
    Vector3 vertex2 = triangle.Point3;
    Vector3 edge1, edge2, h, s, q;
    float a, f, u, v;
    edge1 = vertex1 - vertex0;
    edge2 = vertex2 - vertex0;
    h = Vector3::Cross(rayVector, edge2);
    a = edge1.Dot(h);
    if (a > -EPSILON && a < EPSILON)
        return nullptr;    // This ray is parallel to this triangle.
    f = 1.0f / a;
    s = rayOrigin - vertex0;
    u = f * s.Dot(h);
    if (u < 0.0 || u > 1.0)
        return nullptr;
    q = Vector3::Cross(s, edge1);
    v = f * rayVector.Dot(q);
    if (v < 0.0f || u + v > 1.0f)
        return nullptr;
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * edge2.Dot(q);
    if (t > EPSILON) // ray intersection
    {
        Vector3 r = rayOrigin + rayVector * t;
        return &r;
    }
    else // This means that there is a line intersection but not a ray intersection.
        return nullptr;
}
