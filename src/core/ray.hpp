#pragma once
/***
 *  Ray
 *  RayDifferential
 */
#include <reina.hpp>
#include <utils/vecmath.hpp>
#include <core/medium.hpp>

namespace reina
{
    class Ray
    {
    public:
        // Ray Public Methods
        Ray() : tMax(Infinity), time(0.f), medium(nullptr) {}
        Ray(const Point3f &o, const Vector3f &d, Float tMax = Infinity, Float time = 0.f,
            const Medium *medium = nullptr)
            : o(o), d(d), tMax(tMax), time(time), medium(medium) {}

        Point3f operator()(Float t) const { return Point3f(o + d * t); }
        bool HasNaNs() const { return (o.HasNaNs() || d.HasNaNs() || std::isnan(tMax)); }
        friend std::ostream &operator<<(std::ostream &os, const Ray &r)
        {
            os << "[o=" << r.o << ", d=" << r.d << ", tMax=" << r.tMax
               << ", time=" << r.time << "]";
            return os;
        }
        // Ray Public Data
        Point3f o;
        Vector3f d;
        mutable Float tMax;
        Float time;
        const Medium *medium; // Medium
    };

    class RayDifferential : public Ray
    {
    public:
        // RayDifferential Public Methods
        RayDifferential() { hasDifferentials = false; }
        RayDifferential(const Point3f &o, const Vector3f &d, Float tMax = Infinity,
                        Float time = 0.f, const Medium *medium = nullptr)
            : Ray(o, d, tMax, time, medium)
        {
            hasDifferentials = false;
        }
        RayDifferential(const Ray &ray) : Ray(ray) { hasDifferentials = false; }
        bool HasNaNs() const
        {
            return Ray::HasNaNs() ||
                   (hasDifferentials && (rxOrigin.HasNaNs() || ryOrigin.HasNaNs() ||
                                         rxDirection.HasNaNs() || ryDirection.HasNaNs()));
        }
        void ScaleDifferentials(Float s)
        {
            rxOrigin = o + (rxOrigin - o) * s;
            ryOrigin = o + (ryOrigin - o) * s;
            rxDirection = d + (rxDirection - d) * s;
            ryDirection = d + (ryDirection - d) * s;
        }

        // RayDiffential Public Data
        bool hasDifferentials;
        Point3f rxOrigin, ryOrigin;
        Vector3f rxDirection, ryDirection;
    };

}