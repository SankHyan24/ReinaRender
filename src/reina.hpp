#pragma once
#include <cstdint>
#include <cstddef>
#include <type_traits>
namespace reina
{
#ifdef REINA_FLOAT_AS_DOUBLE
    using Float = double;
    using FloatBits = uint64_t;
#else
    using Float = float;
    using FloatBits = uint32_t;
#endif
    static_assert(sizeof(Float) == sizeof(FloatBits), "Float and FloatBits must have the same size");

    // vecmath
    template <typename T>
    class Vector3;
    template <typename T>
    class Point3;
    template <typename T>
    class Point2;
    template <typename T>
    class Vector2;
    template <typename T>
    class Normal3;
    template <typename T>
    class Bounds2;
    template <typename T>
    class Bounds3;

    using Point2f = Point2<Float>;
    using Point2i = Point2<int>;
    using Point3f = Point3<Float>;
    using Point3i = Point3<int>;

    using Vector2f = Vector2<Float>;
    using Vector2i = Vector2<int>;
    using Vector3f = Vector3<Float>;
    using Vector3i = Vector3<int>;

    class Quaternion;

    using Normal3f = Normal3<Float>;
    using Normal3i = Normal3<int>;
    using Bounds2f = Bounds2<Float>;
    using Bounds2i = Bounds2<int>;
    using Bounds3f = Bounds3<Float>;
    using Bounds3i = Bounds3<int>;

    // ray
    class Ray;
    class RayDifferential;

    // medium
    class Medium;

}