#pragma once

#include <cmath>
#include <cstdint>
#include <cstring>
#include <limits>
#include <string>

#include <reina.hpp>

namespace reina
{
    static constexpr Float Infinity = std::numeric_limits<Float>::infinity();

    static constexpr Float MachineEpsilon = std::numeric_limits<Float>::epsilon() * 0.5;

    static constexpr double DoubleOneMinusEpsilon = 0x1.fffffffffffffp-1;
    static constexpr float FloatOneMinusEpsilon = 0x1.fffffep-1;
#ifdef REINA_FLOAT_AS_DOUBLE
    static constexpr double OneMinusEpsilon = DoubleOneMinusEpsilon;
#else
    static constexpr float OneMinusEpsilon = FloatOneMinusEpsilon;
#endif
}