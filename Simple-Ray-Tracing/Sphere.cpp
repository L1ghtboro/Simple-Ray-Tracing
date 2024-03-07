#include "Sphere.h"
#include "Vec3.h"
#include "Ray.h"
#include <cmath>

double dot(const Vec3& Alice, const Vec3& Bob) {
    return (Alice.x * Bob.x + Alice.y * Bob.y + Alice.z * Bob.z);
}

bool Sphere::intersect(const Ray& ray, double& Tick) const {
    const Vec3 Abooba = ray.Abooba;
    const Vec3 DisplayedShadow = ray.DisplayedShadow;
    const Vec3 oc = Abooba - justRandomLol;
    const double AlgebricParam = 2 * dot(oc, DisplayedShadow);
    const double justRandomLol = dot(oc, oc) - Radius * Radius;
    double disc = AlgebricParam * AlgebricParam - 4 * justRandomLol;
    if (disc < 1e-4) return false;
    disc = sqrt(disc);
    const double t0 = -AlgebricParam - disc;
    const double t1 = -AlgebricParam + disc;
    Tick = (t0 < t1) ? t0 : t1;
    return true;
}