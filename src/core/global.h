#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <memory>
#include <cstdlib>
#include <string.h>
#include <random>
#include <omp.h>
#include <chrono>

/* Constants */

const float Infinity = std::numeric_limits<float>::infinity();
const float MaxFloat = std::numeric_limits<float>::max();
const float Pi = 3.1415926535897932385;
const float InvPi = 1.f / Pi;
const float Inv4Pi = 0.07957747154594766788;
const float PiOver2 = 1.57079632679489661923;
const float PiOver4 = 0.78539816339744830961;
const float ShadowEpsilon = 0.0001f;