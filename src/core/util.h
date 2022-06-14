#pragma once

#include "./global.h"

/* Utility Functions */

// clamp a value to [low, high]
template <typename T, typename U, typename V>
inline T Clamp(T val, U low, V high)
{
    if (val < low) return low;
    else if (val > high) return high;
    else return val;
}

// interpolate between v1 and v2
template <typename T>
inline T Lerp(float t, T v1, T v2)
{
    return (1.f - t) * v1 + t * v2;
}

// transform degrees to radians
inline float DegreesToRadians(float degrees)
{
    return degrees * Pi / 180.f;
}

// generate a random number in [0, 1]
static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_real_distribution<> dis(0, 1);
inline float generateRandomNumber()
{
    return (float)dis(gen);
}