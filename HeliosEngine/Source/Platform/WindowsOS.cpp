#include "WindowsOS.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include "WindowsWindow.h"

namespace Helios
{
    WindowsOS::WindowsOS()
    {   
        if(!glfwInit())
            std::cout << "Failed to initialize GLFW";
    }

    WindowsOS::~WindowsOS()
    {
        glfwTerminate();
    }

    Window* WindowsOS::CreateNativeWindow(WindowProps props)
    {
        return new WindowsWindow(props);
    }

    void WindowsOS::NativeOpenURL(const std::string& url)
    {
        ShellExecute(NULL, "open", url.c_str(), NULL, NULL , SW_SHOWNORMAL);
    }
}