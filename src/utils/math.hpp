#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <limits>
#include <string>

#include <reina.hpp>

namespace reina
{
    inline Float Lerp(Float t, Float v1, Float v2)
    {
        return (1 - t) * v1 + t * v2;
    }
}
