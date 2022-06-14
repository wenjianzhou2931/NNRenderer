#pragma once

#include "./global.h"
#include "./util.h"

/********** Vector And Relative Operations Start **********/

class Vector2f 
{
public:
    Vector2f() { x = y = 0; }
    Vector2f(const float &xx, const float &yy) : x(xx), y(yy) {}
    Vector2f(const Vector2f &v) : x(v.x), y(v.y) {}

    bool HasNaNs() const
    {
        return std::isnan(x) || std::isnan(y);
    }

    Vector2f &operator=(const Vector2f &v)
    {
        x = v.x; y = v.y;
        return *this;
    }

    Vector2f operator+(const Vector2f &v) const 
    {
        return Vector2f(x + v.x, y + v.y);
    }

    Vector2f &operator+=(const Vector2f &v)
    {
        x += v.x; y += v.y;
        return *this;
    }

    Vector2f operator-(const Vector2f &v) const
    {
        return Vector2f(x - v.x, y - v.y);
    }

    Vector2f &operator-=(const Vector2f &v)
    {
        x -= v.x; y -= v.y;
        return *this;
    }

    Vector2f operator*(const float &f) const 
    {
        return Vector2f(f * x, f * y);
    }

    Vector2f operator*(const Vector2f &v) const 
    {
        return Vector2f(v.x * x, v.y * y);
    }

    Vector2f &operator*=(const float &f)
    {
        x *= f; y *= f;
        return *this;
    }

    Vector2f operator/(const float &f) const 
    {
        float inv = 1.f / f;
        return Vector2f(x * inv, y * inv);
    }

    Vector2f &operator/=(const float &f)
    {
        float inv = 1.f / f;
        x *= inv; y *= inv;
        return *this;
    }

    Vector2f operator-() const { return Vector2f(-x, -y); }
    
    float operator[](int i) const 
    {
        if (i == 0) return x;
        return y;
    }

    float &operator[](int i)
    {
        if (i == 0) return x;
        return y;
    }

    bool operator==(const Vector2f &v) const 
    {
        return x == v.x && y == v.y;
    }

    bool operator!=(const Vector2f &v) const 
    {
        return x != v.x || y != v.y;
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector2f &v)
    {
        os << "[" << v.x << ", " << v.y << "]";
        return os;
    }

    float LengthSquared() const { return x * x + y * y; }
    float Length() const { return std::sqrt(LengthSquared()); }

public:
    float x, y;
};

class Vector3f
{
public:
    Vector3f() { x = y = z = 0; }
    Vector3f(const float &xx, const float &yy, const float &zz) : x(xx), y(yy), z(zz) {}
    Vector3f(const Vector3f &v) : x(v.x), y(v.y), z(v.z) {}

    bool HasNaNs() const
    {
        return std::isnan(x) || std::isnan(y) || std::isnan(z);
    }

    Vector3f &operator=(const Vector3f &v)
    {
        x = v.x; y = v.y; z = v.z;
        return *this;
    }

    Vector3f operator+(const Vector3f &v) const 
    {
        return Vector3f(x + v.x, y + v.y, z + v.z);
    }

    Vector3f &operator+=(const Vector3f &v)
    {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }

    Vector3f operator-(const Vector3f &v) const
    {
        return Vector3f(x - v.x, y - v.y, z - v.z);
    }

    Vector3f &operator-=(const Vector3f &v)
    {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }

    Vector3f operator*(const float &f) const 
    {
        return Vector3f(f * x, f * y, f * z);
    }

    Vector3f operator*(const Vector3f &v) const 
    {
        return Vector3f(v.x * x, v.y * y, v.z * z);
    }

    Vector3f &operator*=(const float &f)
    {
        x *= f; y *= f; z *= f;
        return *this;
    }

    Vector3f operator/(const float &f) const 
    {
        float inv = 1.f / f;
        return Vector3f(x * inv, y * inv, z * inv);
    }

    Vector3f &operator/=(const float &f)
    {
        float inv = 1.f / f;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }

    Vector3f operator-() const { return Vector3f(-x, -y, -z); }
    
    float operator[](int i) const 
    {
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    float &operator[](int i)
    {
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    bool operator==(const Vector3f &v) const 
    {
        return x == v.x && y == v.y && z == v.z;
    }

    bool operator!=(const Vector3f &v) const 
    {
        return x != v.x || y != v.y || z != v.z;
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector3f &v)
    {
        os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        return os;
    }

    float LengthSquared() const { return x * x + y * y + z * z; }
    float Length() const { return std::sqrt(LengthSquared()); }

public:
    float x, y, z;
};

/* Vector Utility Functions */

inline Vector3f Abs(const Vector3f &v)
{
    return Vector3f(std::abs(v.x), std::abs(v.y), std::abs(v.z));
}

inline float Dot(const Vector3f &v1, const Vector3f &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline float AbsDot(const Vector3f &v1, const Vector3f &v2)
{
    return std::abs(Dot(v1, v2));
}

inline Vector3f Cross(const Vector3f &v1, const Vector3f &v2)
{
    return Vector3f(
        (v1.y * v2.z) - (v1.z * v2.y),
        (v1.z * v2.x) - (v1.x * v2.z),
        (v1.x * v2.y) - (v1.y * v2.x));
}

inline Vector3f Normalize(const Vector3f &v) { return v / v.Length(); }

inline float MinComponent(const Vector3f &v)
{
    return std::min(v.x, std::min(v.y, v.z));
}

inline float MaxComponent(const Vector3f &v)
{
    return std::max(v.x, std::max(v.y, v.z));
}

inline Vector3f Min(const Vector3f &v1, const Vector3f &v2)
{
    return Vector3f(std::min(v1.x, v2.x), std::min(v1.y, v2.y), std::min(v1.z, v2.z));
}

inline Vector3f Max(const Vector3f &v1, const Vector3f &v2)
{
    return Vector3f(std::max(v1.x, v2.x), std::max(v1.y, v2.y), std::max(v1.z, v2.z));
}

inline Vector3f Permute(const Vector3f &v, int x, int y, int z)
{
    return Vector3f(v[x], v[y], v[z]);
}

inline void CoordinateSystem(const Vector3f &v1, Vector3f *v2, Vector3f *v3)
{
    if (std::abs(v1.x) > std::abs(v1.y))
    {
        *v2 = Vector3f(-v1.z, 0, v1.x) /
              std::sqrt(v1.x * v1.x + v1.z * v1.z);
    }
    else
    {
        *v2 = Vector3f(0, v1.z, -v1.y) /
              std::sqrt(v1.y * v1.y + v1.z * v1.z);
    }
    *v3 = Cross(v1, *v2);
}

inline float Distance(const Vector3f &v1, const Vector3f &v2)
{
    return (v1 - v2).Length();
}

inline float DistanceSquared(const Vector3f &v1, const Vector3f &v2)
{
    return (v1 - v2).LengthSquared();
}

inline Vector3f Floor(const Vector3f &v)
{
    return Vector3f(std::floor(v.x), std::floor(v.y), std::floor(v.z));
}

inline Vector3f Ceil(const Vector3f &v)
{
    return Vector3f(std::ceil(v.x), std::ceil(v.y), std::ceil(v.z));
}

inline Vector3f FaceForward(const Vector3f &normal, const Vector3f &v)
{
    return (Dot(normal, v) < 0.f) ? -normal : normal;
}

/********** Vector And Relative Operations End **********/

// TODO: Bounds3f