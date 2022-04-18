#pragma once
#include "Core/Events/Event.h"

namespace Helios
{
    class Layer
    {
    public:
        Layer() = default;
        virtual ~Layer() = default;

        virtual void OnAttach() {}

        virtual void OnDetach() {}

        virtual void OnEvent(Event& event) {}

        virtual void OnUpdate(double dt) {}

        virtual void OnUIRender() {}
    };
}