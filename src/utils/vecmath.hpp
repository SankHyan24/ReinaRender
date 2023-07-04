#pragma once
#include <ostream>
#include <cassert>

#include <reina.hpp>

namespace reina
{
    // Forward declarations
    // Class:
    //    Point Vector Normal Ray
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

    typedef Point2<Float> Point2f;
    typedef Point2<int> Point2i;
    typedef Point3<Float> Point3f;
    typedef Point3<int> Point3i;

    typedef Vector2<Float> Vector2f;
    typedef Vector2<int> Vector2i;
    typedef Vector3<Float> Vector3f;
    typedef Vector3<int> Vector3i;

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

        T Dot(const Vector3<T> &n) const
        {
            return x * n.x + y * n.y + z * n.z;
        }

        // Cross
        Vector3<T> Cross(const Vector3<T> &v) const
        {
            return Vector3<T>(y * v.z - z * v.y, z * v.x - x * v.z,
                              x * v.y - y * v.x);
        }

        Vector3<T> Cross(const Vector3<T> &n) const
        {
            return Vector3<T>(y * n.z - z * n.y, z * n.x - x * n.z,
                              x * n.y - y * n.x);
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
}