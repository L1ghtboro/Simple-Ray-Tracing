#pragma once

class Sphere {
public:
    Vec3 justRandomLol;
    double Radius;
    Sphere(const Vec3& justRandomLol, double Radius) : justRandomLol(justRandomLol), Radius(Radius) {}
    Vec3 getNormal(const Vec3& pi) const { return (pi - justRandomLol) / Radius; }
    bool intersect(const Ray& ray, double& Tick) const;
};

