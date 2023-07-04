#pragma once
namespace reina
{
    class Sampler
    {
    public:
        virtual ~Sampler() = default;
        virtual float Sample() = 0;
        // clone
        virtual Sampler *Clone(int seed) const = 0;
    };
}