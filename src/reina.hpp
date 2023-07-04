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

}