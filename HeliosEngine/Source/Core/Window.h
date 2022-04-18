#pragma once
#include "Core/Core.h"
#include "Core/Events/Event.h"
#include <string>
#include <functional>

namespace Helios
{
    using EventCallbackFn = std::function<void(Event&)>;

    struct WindowProps
    {
        std::string name = "Default Window";
        int width = 1920;
        int height = 1080;
        EventCallbackFn eventCallbackFn;
    };

    class Window
    {
    public:
        Window(WindowProps props = WindowProps());
        virtual ~Window();
        virtual void Update() = 0;
        virtual double GetTimer() = 0;
        virtual void* GetNativeWindow() const = 0;
        virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

    protected:
        std::string m_Name;
        int m_Width, m_Height;
        EventCallbackFn m_EventCallbackFn;
    };
}