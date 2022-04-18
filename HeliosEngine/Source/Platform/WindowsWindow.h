#pragma once
#include "Core/Window.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <glad/glad.h>

namespace Helios
{
    struct WindowData
    {
        std::string name;
        unsigned int width, height;
        bool vSync;

        EventCallbackFn eventCallbackFn;
    };

    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(WindowProps props);
        ~WindowsWindow();
        void Update() override;
        double GetTimer() override;
        inline virtual void *GetNativeWindow() const { return m_Handle; }
        inline unsigned int GetWidth() const override { return m_Data.width; }
		inline unsigned int GetHeight() const override { return m_Data.height; }
        
    private:
        GLFWwindow* m_Handle;
        WindowData m_Data;
    };
}

