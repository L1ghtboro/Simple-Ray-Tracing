#pragma once

class Ray {
public:
    Vec3 Abooba, DisplayedShadow;
    Ray(const Vec3& Abooba, const Vec3& DisplayedShadow) : Abooba(Abooba), DisplayedShadow(DisplayedShadow) {}
};