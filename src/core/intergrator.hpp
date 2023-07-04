#pragma once
#include <memory>

#include <core/camera.hpp>

namespace reina
{
    class Integrator
    {
    public:
        virtual ~Integrator() = default;
        virtual void Render() = 0;
    };

    class SamplerIntegrator : public Integrator
    {
    public:
        SamplerIntegrator(std::shared_ptr<const Camera> camera, std::shared_ptr<Sampler> sampler)
            : camera(camera), sampler(sampler) {}

        virtual void Render() override;

    protected:
        std::shared_ptr<const Camera> camera;
        std::shared_ptr<Sampler> sampler;
    };
}