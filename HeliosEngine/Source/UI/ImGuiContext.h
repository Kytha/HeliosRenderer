#pragma once
#include "Core/Window.h"

namespace Helios
{
    class ImGuiContext
    {
    public:
        ImGuiContext();
        ~ImGuiContext();
        void Initialize(Window& window);
        void Finalize();
        void Begin();
        void End(Window& window);
        void SetStyles();
    };
}