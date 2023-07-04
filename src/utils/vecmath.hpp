#pragma once
#include <ostream>
#include <cassert>
#include <string>

#include <reina.hpp>
#include <utils/math.hpp>
#include <utils/float.hpp>

namespace reina
{
    template <typename T>
    class Point2
    {
    public:
        explicit Point2(const Point3<T> &p) : x(p.x), y(p.y)
        {
            assert(!HasNaNs());
        }

        Point2() { x = y = 0; }
        Point2(T x, T y) : x(x), y(y)
        {
            assert(!HasNaNs());
        }
        template <typename U>
        explicit Point2(const Point2<U> &p)
        {
            x = (T)p.x;
            y = (T)p.y;
            assert(!HasNaNs());
        }
        template <typename U>
        explicit Point2(const Vector2<U> &p)
        {
            x = (T)p.x;
            y = (T)p.y;
            assert(!HasNaNs());
        }
        template <typename U>
        explicit operator Vector2<U>() const
        {
            return Vector2<U>(x, y);
        }
        bool HasNaNs() const { return std::isnan(x) || std::isnan(y); }
        // Point2 Public Methods
        Point2<T> operator+(const Vector2<T> &v) const
        {
            assert(!v.HasNaNs());
            return Point2<T>(x + v.x, y + v.y);
        }

        Point2<T> &operator+=(const Vector2<T> &v)
        {
            assert(!v.HasNaNs());
            x += v.x;
            y += v.y;
            return *this;
        }

        Vector2<T> operator-(const Point2<T> &p) const
        {
            assert(!p.HasNaNs());
            return Vector2<T>(x - p.x, y - p.y);
        }

        Point2<T> operator-(const Vector2<T> &v) const
        {
            assert(!v.HasNaNs());
            return Point2<T>(x - v.x, y - v.y);
        }

        Point2<T> &operator-=(const Vector2<T> &v)
        {
            assert(!v.HasNaNs());
            x -= v.x;
            y -= v.y;
            return *this;
        }

        Point2<T> &operator+=(const Point2<T> &p)
        {
            assert(!p.HasNaNs());
            x += p.x;
            y += p.y;
            return *this;
        }

        Point2<T> operator+(const Point2<T> &p) const
        {
            assert(!p.HasNaNs());
            return Point2<T>(x + p.x, y + p.y);
        }

        Point2<T> operator*(T f) const { return Point2<T>(f * x, f * y); }

        Point2<T> &operator*=(T f)
        {
            x *= f;
            y *= f;
            return *this;
        }

        Point2<T> operator/(T f) const
        {
            assert(f != 0);
            Float inv = (Float)1 / f;
            return Point2<T>(x * inv, y * inv);
        }

        Point2<T> &operator/=(T f)
        {
            assert(f != 0);
            Float inv = (Float)1 / f;
            x *= inv;
            y *= inv;
            return *this;
        }

        T operator[](int i) const
        {
            assert(i >= 0 && i <= 1);
            if (i == 0)
                return x;
            return y;
        }

        T &operator[](int i)
        {
            assert(i >= 0 && i <= 1);
            if (i == 0)
                return x;
            return y;
        }

        bool operator==(const Point2<T> &p) const
        {
            return x == p.x && y == p.y;
        }

        bool operator!=(const Point2<T> &p) const
        {
            return x != p.x || y != p.y;
        }

        // Point2 Public Data
        T x, y;
    };

    template <typename T>
    class Point3
    {
    public:
        Point3()
        {
            x = y = z = 0;
        }

        Point3(T x, T y, T z) : x(x), y(y), z(z)
        {
            assert(!HasNaNs());
        }

        template <typename U>
        explicit Point3(const Point3<U> &p)
        {
            x = (T)p.x;
            y = (T)p.y;
            z = (T)p.z;
            assert(!HasNaNs());
        }

        template <typename U>
        explicit operator Vector3<U>() const
        {
            return Vector3<U>(x, y, z);
        }

        bool HasNaNs() const { return std::isnan(x) || std::isnan(y) || std::isnan(z); }

        // Point3 Public Methods
        friend std::ostream &operator<<(std::ostream &os, const Point3<T> &p)
        {
            os << "[ " << p.x << ", " << p.y << ", " << p.z << " ]";
            return os;
        }

        Point3<T> operator+(const Vector3<T> &v) const
        {
            assert(!v.HasNaNs());
            return Point3<T>(x + v.x, y + v.y, z + v.z);
        }

        Point3<T> &operator+=(const Vector3<T> &v)
        {
            assert(!v.HasNaNs());
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        Vector3<T> operator-(const Point3<T> &p) const
        {
            assert(!p.HasNaNs());
            return Vector3<T>(x - p.x, y - p.y, z - p.z);
        }

        Point3<T> operator-(const Vector3<T> &v) const
        {
            assert(!v.HasNaNs());
            return Point3<T>(x - v.x, y - v.y, z - v.z);
        }

        Point3<T> &operator-=(const Vector3<T> &v)
        {
            assert(!v.HasNaNs());
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        Point3<T> &operator+=(const Point3<T> &p)
        {
            assert(!p.HasNaNs());
            x += p.x;
            y += p.y;
            z += p.z;
            return *this;
        }

        Point3<T> operator+(const Point3<T> &p) const
        {
            assert(!p.HasNaNs());
            return Point3<T>(x + p.x, y + p.y, z + p.z);
        }

        Point3<T> operator*(T f) const { return Point3<T>(f * x, f * y, f * z); }

        Point3<T> &operator*=(T f)
        {
            x *= f;
            y *= f;
            z *= f;
            return *this;
        }

        Point3<T> operator/(T f) const
        {
            assert(f != 0);
            Float inv = (Float)1 / f;
            return Point3<T>(x * inv, y * inv, z * inv);
        }

        Point3<T> &operator/=(T f)
        {
            assert(f != 0);
            Float inv = (Float)1 / f;
            x *= inv;
            y *= inv;
            z *= inv;
            return *this;
        }

        T operator[](int i) const
        {
            assert(i >= 0 && i <= 2);
            if (i == 0)
                return x;
            if (i == 1)
                return y;
            return z;
        }

        T &operator[](int i)
        {
            assert(i >= 0 && i <= 2);
            if (i == 0)
                return x;
            if (i == 1)
                return y;
            return z;
        }

        bool operator==(const Point3<T> &p) const
        {
            return x == p.x && y == p.y && z == p.z;
        }

        bool operator!=(const Point3<T> &p) const
        {
            return x != p.x || y != p.y || z != p.z;
        }

        // Point3 Public Data
        T x, y, z;
    };

    template <typename T>
    class Vector2
    {
    public:
        Vector2() : x(0), y(0) {}
        Vector2(T x, T y) : x(x), y(y) {}
        Vector2(const Vector2 &v) : x(v.x), y(v.y) {}
        bool HasNaNs() const { return std::isnan(x) || std::isnan(y); }
        explicit Vector2(const Point2<T> &p) : x(p.x), y(p.y) {}
        explicit Vector2(const Point3<T> &p) : x(p.x), y(p.y) {}

        // Vector2 Public Methods
        friend std::ostream &operator<<(std::ostream &os, const Vector2<T> &v)
        {
            os << "[ " << v.x << ", " << v.y << " ]";
            return os;
        }

        Vector2<T> operator+(const Vector2<T> &v) const
        {
            assert(!v.HasNaNs());
            return Vector2<T>(x + v.x, y + v.y);
        }

        Vector2<T> &operator+=(const Vector2<T> &v)
        {
            assert(!v.HasNaNs());
            x += v.x;
            y += v.y;
            return *this;
        }

        Vector2<T> operator-(const Vector2<T> &v) const
        {
            assert(!v.HasNaNs());
            return Vector2<T>(x - v.x, y - v.y);
        }

        Vector2<T> &operator-=(const Vector2<T> &v)
        {
            assert(!v.HasNaNs());
            x -= v.x;
            y -= v.y;
            return *this;
        }

        bool operator==(const Vector2<T> &v) const
        {
            return x == v.x && y == v.y;
        }

        bool operator!=(const Vector2<T> &v) const
        {
            return x != v.x || y != v.y;
        }

        Vector2<T> operator*(T s) const { return Vector2<T>(x * s, y * s); }

        Vector2<T> &operator*=(T s)
        {
            assert(!std::isnan(s));
            x *= s;
            y *= s;
            return *this;
        }

        Vector2<T> operator/(T s) const
        {
            assert(s != 0);
            Float inv = (Float)1 / s;
            return Vector2<T>(x * inv, y * inv);
        }

        Vector2<T> &operator/=(T s)
        {
            assert(s != 0);
            Float inv = (Float)1 / s;
            x *= inv;
            y *= inv;
            return *this;
        }

        Vector2<T> operator-() const { return Vector2<T>(-x, -y); }

        T &operator[](int i)
        {
            assert(i >= 0 && i <= 1);
            if (i == 0)
                return x;
            return y;
        }

        Float LengthSquared() const { return x * x + y * y; }

        Float Length() const { return std::sqrt(LengthSquared()); }

        // Vector2 Public Data
        T x, y;
    };

    template <typename T>
    class Vector3
    {
    public:
        Vector3() : x(0), y(0), z(0) {}
        Vector3(T x, T y, T z) : x(x), y(y), z(z) {}
        Vector3(const Vector3 &v) : x(v.x), y(v.y), z(v.z) {}
        Vector3(const Normal3<T> &n) : x(n.x), y(n.y), z(n.z) {}
        bool HasNaNs() const { return std::isnan(x) || std::isnan(y) || std::isnan(z); }
        explicit Vector3(const Point3<T> &p) : x(p.x), y(p.y), z(p.z) {}
        explicit Vector3(const Point2<T> &p) : x(p.x), y(p.y), z(0) {}

        // Vector3 Public Methods
        friend std::ostream &operator<<(std::ostream &os, const Vector3<T> &v)
        {
            os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
            return os;
        }

        Vector3<T> operator+(const Vector3<T> &v) const
        {
            assert(!v.HasNaNs());
            return Vector3<T>(x + v.x, y + v.y, z + v.z);
        }

        Vector3<T> &operator+=(const Vector3<T> &v)
        {
            assert(!v.HasNaNs());
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        Vector3<T> operator-(const Vector3<T> &v) const
        {
            assert(!v.HasNaNs());
            return Vector3<T>(x - v.x, y - v.y, z - v.z);
        }

        Vector3<T> &operator-=(const Vector3<T> &v)
        {
            assert(!v.HasNaNs());
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        bool operator==(const Vector3<T> &v) const
        {
            return x == v.x && y == v.y && z == v.z;
        }

        bool operator!=(const Vector3<T> &v) const
        {
            return x != v.x || y != v.y || z != v.z;
        }

        Vector3<T> operator*(T s) const { return Vector3<T>(x * s, y * s, z * s); }

        Vector3<T> &operator*=(T s)
        {
            assert(!std::isnan(s));
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }

        Vector3<T> operator/(T s) const
        {
            assert(s != 0);
            Float inv = (Float)1 / s;
            return Vector3<T>(x * inv, y * inv, z * inv);
        }

        Vector3<T> &operator/=(T s)
        {
            assert(s != 0);
            Float inv = (Float)1 / s;
            x *= inv;
            y *= inv;
            z *= inv;
            return *this;
        }

        Vector3<T> operator-() const { return Vector3<T>(-x, -y, -z); }

        T &operator[](int i)
        {
            assert(i >= 0 && i <= 2);
            if (i == 0)
                return x;
            if (i == 1)
                return y;
            return z;
        }

        Float LengthSquared() const { return x * x + y * y + z * z; }

        Float Length() const { return std::sqrt(LengthSquared()); }

        // Dot
        T Dot(const Vector3<T> &v) const
        {
            return x * v.x + y * v.y + z * v.z;
        }

        // Cross
        Vector3<T> Cross(const Vector3<T> &v) const
        {
            return Vector3<T>(y * v.z - z * v.y, z * v.x - x * v.z,
                              x * v.y - y * v.x);
        }

        std::string ToString() const
        {
            return std::string("[ " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + " ]");
        }
        // Vector3 Public Data
        T x, y, z;
    };

    template <typename T>
    inline Float Distance(const Point3<T> &p1, const Point3<T> &p2)
    {
        return (p1 - p2).Length();
    }

    template <typename T>
    inline Float DistanceSquared(const Point3<T> &p1, const Point3<T> &p2)
    {
        return (p1 - p2).LengthSquared();
    }

    template <typename T>
    inline Point3<T> Lerp(Float t, const Point3<T> &p0, const Point3<T> &p1)
    {
        return (1 - t) * p0 + t * p1;
    }

    template <typename T>
    inline Point3<T> Min(const Point3<T> &p1, const Point3<T> &p2)
    {
        return Point3<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y),
                         std::min(p1.z, p2.z));
    }

    template <typename T>
    inline Point3<T> Max(const Point3<T> &p1, const Point3<T> &p2)
    {
        return Point3<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y),
                         std::max(p1.z, p2.z));
    }

    // Floor Ceil and Abs

    template <typename T>
    inline Vector3<T> Abs(const Vector3<T> &v)
    {
        return Vector3<T>(std::abs(v.x), std::abs(v.y), std::abs(v.z));
    }

    template <typename T>
    inline Vector3<T> Floor(const Vector3<T> &v)
    {
        return Vector3<T>(std::floor(v.x), std::floor(v.y), std::floor(v.z));
    }

    template <typename T>
    inline Vector3<T> Ceil(const Vector3<T> &v)
    {
        return Vector3<T>(std::ceil(v.x), std::ceil(v.y), std::ceil(v.z));
    }

    template <typename T>
    Point3<T> Permute(const Point3<T> &p, int x, int y, int z)
    {
        return Point3<T>(p[x], p[y], p[z]);
    }

    // Normal

    template <typename T>
    class Normal3
    {
    public:
        Normal3() { x = y = z = 0; }
        Normal3(T x, T y, T z) : x(x), y(y), z(z) { assert(!HasNaNs()); }
        Normal3(const Normal3<T> &n) : x(n.x), y(n.y), z(n.z) { assert(!HasNaNs()); }
        explicit Normal3<T>(const Vector3<T> &v) : x(v.x), y(v.y), z(v.z) { assert(!HasNaNs()); }
        explicit Normal3<T>(const Point3<T> &p) : x(p.x), y(p.y), z(p.z) { assert(!HasNaNs()); }
        template <typename U>
        explicit Normal3<T>(const Normal3<U> &n)
        {
            x = (T)n.x;
            y = (T)n.y;
            z = (T)n.z;
            assert(!HasNaNs());
        }

        bool HasNaNs() const { return std::isnan(x) || std::isnan(y) || std::isnan(z); }

        // Normal3 Public Methods
        friend std::ostream &operator<<(std::ostream &os, const Normal3<T> &n)
        {
            os << "[ " << n.x << ", " << n.y << ", " << n.z << " ]";
            return os;
        }

        Normal3<T> operator+(const Normal3<T> &n) const
        {
            assert(!n.HasNaNs());
            return Normal3<T>(x + n.x, y + n.y, z + n.z);
        }

        Normal3<T> &operator+=(const Normal3<T> &n)
        {
            assert(!n.HasNaNs());
            x += n.x;
            y += n.y;
            z += n.z;
            return *this;
        }

        Normal3<T> operator-(const Normal3<T> &n) const
        {
            assert(!n.HasNaNs());
            return Normal3<T>(x - n.x, y - n.y, z - n.z);
        }

        Normal3<T> &operator-=(const Normal3<T> &n)
        {
            assert(!n.HasNaNs());
            x -= n.x;
            y -= n.y;
            z -= n.z;
            return *this;
        }

        bool operator==(const Normal3<T> &n) const
        {
            return x == n.x && y == n.y && z == n.z;
        }

        bool operator!=(const Normal3<T> &n) const
        {
            return x != n.x || y != n.y || z != n.z;
        }

        Normal3<T> operator*(T f) const { return Normal3<T>(f * x, f * y, f * z); }

        Normal3<T> &operator*=(T f)
        {
            x *= f;
            y *= f;
            z *= f;
            return *this;
        }

        Normal3<T> operator/(T f) const
        {
            assert(f != 0);
            Float inv = (Float)1 / f;
            return Normal3<T>(x * inv, y * inv, z * inv);
        }

        Normal3<T> &operator/=(T f)
        {
            assert(f != 0);
            Float inv = (Float)1 / f;
            x *= inv;
            y *= inv;
            z *= inv;
            return *this;
        }

        Normal3<T> operator-() const { return Normal3<T>(-x, -y, -z); }

        T operator[](int i) const
        {
            assert(i >= 0 && i <= 2);
            if (i == 0)
                return x;
            if (i == 1)
                return y;
            return z;
        }

        T &operator[](int i)
        {
            assert(i >= 0 && i <= 2);
            if (i == 0)
                return x;
            if (i == 1)
                return y;
            return z;
        }

        Float LengthSquared() const { return x * x + y * y + z * z; }

        Float Length() const { return std::sqrt(LengthSquared()); }

        // Dot
        T Dot(const Vector3<T> &v) const
        {
            return x * v.x + y * v.y + z * v.z;
        }

        T Dot(const Normal3<T> &n) const
        {
            return x * n.x + y * n.y + z * n.z;
        }

        // Cross
        Vector3<T> Cross(const Vector3<T> &v) const
        {
            return Vector3<T>(y * v.z - z * v.y, z * v.x - x * v.z,
                              x * v.y - y * v.x);
        }

        Vector3<T> Cross(const Normal3<T> &n) const
        {
            return Vector3<T>(y * n.z - z * n.y, z * n.x - x * n.z,
                              x * n.y - y * n.x);
        }

        // Normal3 Public Data
        T x, y, z;
    };

    template <typename T>
    inline Normal3<T> operator*(T f, const Normal3<T> &n)
    {
        assert(!n.HasNaNs());
        return n * f;
    }

    template <typename T>
    inline Normal3<T> Normalize(const Normal3<T> &n)
    {
        return n / n.Length();
    }

    template <typename T>
    inline Normal3<T> Faceforward(const Normal3<T> &n, const Vector3<T> &v)
    {
        return (n.Dot(v) < 0.f) ? -n : n;
    }

    class Quaternion
    {
    public:
        // Quaternion Public Methods
        Quaternion() = default;
        Quaternion &operator+=(Quaternion q)
        {
            v += q.v;
            w += q.w;
            return *this;
        }

        Quaternion operator+(Quaternion q) const { return {v + q.v, w + q.w}; }
        Quaternion &operator-=(Quaternion q)
        {
            v -= q.v;
            w -= q.w;
            return *this;
        }
        Quaternion operator-() const { return {-v, -w}; }
        Quaternion operator-(Quaternion q) const { return {v - q.v, w - q.w}; }
        Quaternion &operator*=(Float f)
        {
            v *= f;
            w *= f;
            return *this;
        }
        Quaternion operator*(Float f) const { return {v * f, w * f}; }
        Quaternion &operator/=(Float f)
        {
            assert(f != 0);
            v /= f;
            w /= f;
            return *this;
        }
        Quaternion operator/(Float f) const
        {
            assert(f != 0);
            return {v / f, w / f};
        }

        std::string ToString() const
        {
            return "Quaternion: " + v.ToString() + " " + std::to_string(w);
        }

        // Quaternion Public Members
        Vector3f v;
        Float w = 1;
    };

    template <typename T>
    class Bounds2
    {
    public:
        // Bounds2 Public Methods
        Bounds2()
        {
            T minNum = std::numeric_limits<T>::lowest();
            T maxNum = std::numeric_limits<T>::max();
            pMin = Point2<T>(maxNum, maxNum);
            pMax = Point2<T>(minNum, minNum);
        }
        Bounds2(const Point2<T> &p) : pMin(p), pMax(p) {}
        Bounds2(const Point2<T> &p1, const Point2<T> &p2)
        {
            pMin = Point2<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
            pMax = Point2<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y));
        }
        template <typename U>
        explicit operator Bounds2<U>() const
        {
            return Bounds2<U>((Point2<U>)pMin, (Point2<U>)pMax);
        }

        Vector2<T> Diagonal() const
        {
            return pMax - pMin;
        }
        T Area() const
        {
            Vector2<T> d = pMax - pMin;
            return (d.x * d.y);
        }
        int MaximumExtent() const
        {
            Vector2<T> diag = Diagonal();
            if (diag.x > diag.y)
                return 0;
            else
                return 1;
        }
        inline const Point2<T> &operator[](int i) const
        {
            assert(i == 0 || i == 1);
            return (i == 0) ? pMin : pMax;
        }
        inline Point2<T> &operator[](int i)
        {
            assert(i == 0 || i == 1);
            return (i == 0) ? pMin : pMax;
        }
        bool operator==(const Bounds2<T> &b) const
        {
            return b.pMin == pMin && b.pMax == pMax;
        }
        bool operator!=(const Bounds2<T> &b) const
        {
            return b.pMin != pMin || b.pMax != pMax;
        }
        Point2<T> Lerp(const Point2f &t) const
        {
            return Point2<T>(reina::Lerp(t.x, pMin.x, pMax.x), reina::Lerp(t.y, pMin.y, pMax.y));
        }
        Vector2<T> Offset(const Point2<T> &p) const
        {
            Vector2<T> o = p - pMin;
            if (pMax.x > pMin.x)
                o.x /= pMax.x - pMin.x;
            if (pMax.y > pMin.y)
                o.y /= pMax.y - pMin.y;
            return o;
        }
        void BoundingSphere(Point2<T> *c, Float *rad) const
        {
            *c = (pMin + pMax) / 2;
            *rad = Inside(*c, *this) ? Distance(*c, pMax) : 0;
        }

        // Bounds2 Public Methods
        Point2<T> pMin, pMax;
    };

    template <typename T>
    class Bounds3
    {
    public:
        // Bounds3 Public Methods
        Bounds3()
        {
            T minNum = std::numeric_limits<T>::lowest();
            T maxNum = std::numeric_limits<T>::max();
            pMin = Point3<T>(maxNum, maxNum, maxNum);
            pMax = Point3<T>(minNum, minNum, minNum);
        }
        Bounds3(const Point3<T> &p) : pMin(p), pMax(p) {}
        Bounds3(const Point3<T> &p1, const Point3<T> &p2)
            : pMin(std::min(p1.x, p2.x), std::min(p1.y, p2.y),
                   std::min(p1.z, p2.z)),
              pMax(std::max(p1.x, p2.x), std::max(p1.y, p2.y),
                   std::max(p1.z, p2.z))
        {
        }
        const Point3<T> &operator[](int i) const
        {
            assert(i == 0 || i == 1);
            return (i == 0) ? pMin : pMax;
        }
        Point3<T> &operator[](int i)
        {
            assert(i == 0 || i == 1);
            return (i == 0) ? pMin : pMax;
        }
        bool operator==(const Bounds3<T> &b) const
        {
            return b.pMin == pMin && b.pMax == pMax;
        }
        bool operator!=(const Bounds3<T> &b) const
        {
            return b.pMin != pMin || b.pMax != pMax;
        }
        Point3<T> Corner(int corner) const
        {
            return Point3<T>((*this)[(corner & 1)].x,
                             (*this)[(corner & 2) ? 1 : 0].y,
                             (*this)[(corner & 4) ? 1 : 0].z);
        }
        Vector3<T> Diagonal() const { return pMax - pMin; }
        T SurfaceArea() const
        {
            Vector3<T> d = Diagonal();
            return 2 * (d.x * d.y + d.x * d.z + d.y * d.z);
        }
        T Volume() const
        {
            Vector3<T> d = Diagonal();
            return d.x * d.y * d.z;
        }
        int MaximumExtent() const
        {
            Vector3<T> d = Diagonal();
            if (d.x > d.y && d.x > d.z)
                return 0;
            else if (d.y > d.z)
                return 1;
            else
                return 2;
        }
        Point3<T> Lerp(const Point3f &t) const
        {
            return Point3<T>(reina::Lerp(t.x, pMin.x, pMax.x),
                             reina::Lerp(t.y, pMin.y, pMax.y),
                             reina::Lerp(t.z, pMin.z, pMax.z));
        }
        Vector3<T> Offset(const Point3<T> &p) const
        {
            Vector3<T> o = p - pMin;
            if (pMax.x > pMin.x)
                o.x /= pMax.x - pMin.x;
            if (pMax.y > pMin.y)
                o.y /= pMax.y - pMin.y;
            if (pMax.z > pMin.z)
                o.z /= pMax.z - pMin.z;
            return o;
        }
        void BoundingSphere(Point3<T> *center, Float *radius) const
        {
            *center = (pMin + pMax) / 2;
            *radius = Inside(*center, *this) ? Distance(*center, pMax) : 0;
        }
        template <typename U>
        explicit operator Bounds3<U>() const
        {
            return Bounds3<U>((Point3<U>)pMin, (Point3<U>)pMax);
        }
        bool IntersectP(const Ray &ray, Float *hitt0 = nullptr, Float *hitt1 = nullptr) const
        {
            throw std::runtime_error("Bounds3::IntersectP not implemented");
            return false;
        }
        inline bool IntersectP(const Ray &ray, const Vector3f &invDir,
                               const int dirIsNeg[3]) const
        {
            throw std::runtime_error("Bounds3::IntersectP not implemented");
            return false;
        }

        // Bounds3 Public Members
        Point3<T> pMin, pMax;
    };

}