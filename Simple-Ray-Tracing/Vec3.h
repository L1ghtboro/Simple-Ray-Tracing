#pragma once

class Vec3 {
public:
    double x, y, z;
    Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
    Vec3 operator + (const Vec3& Vector) const { return Vec3(x + Vector.x, y + Vector.y, z + Vector.z); }
    Vec3 operator - (const Vec3& Vector) const { return Vec3(x - Vector.x, y - Vector.y, z - Vector.z); }
    Vec3 operator * (double inDouble) const { return Vec3(x * inDouble, y * inDouble, z * inDouble); }
    Vec3 operator / (double inDouble) const { return Vec3(x / inDouble, y / inDouble, z / inDouble); }
    Vec3 normalize() const { double Vector = sqrt(x * x + y * y + z * z); return Vec3(x / Vector, y / Vector, z / Vector); }

};