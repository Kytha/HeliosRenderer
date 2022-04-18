#include "WindowsWindow.h"
#include <iostream>
#include "Core/Events/Event.h"

#define WINDOW_CALLBACK_PREAMBLE WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window); \
if(!data.eventCallbackFn) return;
 
namespace Helios
{
    WindowsWindow::WindowsWindow(WindowProps props) : Window(props)
    {
        m_Data.height = props.height;
        m_Data.width = props.width;
        m_Data.name = props.name;
        m_Data.eventCallbackFn = props.eventCallbackFn;

        glfwWindowHint(GLFW_MAXIMIZED , GL_TRUE);
        m_Handle = glfwCreateWindow(props.width, props.height, props.name.c_str(), NULL, NULL);
        glfwMakeContextCurrent(m_Handle);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            std::cout << "Failed to initialize Glad!";

        glfwSetWindowUserPointer(m_Handle,&m_Data);

        glfwSetKeyCallback(m_Handle, [](GLFWwindow* window, int key, int scancode, int action, int mods)
            {
                WINDOW_CALLBACK_PREAMBLE
                if(action == GLFW_PRESS)
                {
                    KeyPressedEvent e;
                    e.keyCode = key;
                    data.eventCallbackFn(e);
                }
                else if (action == GLFW_RELEASE)
                {
                    KeyReleasedEvent e;
                    e.keyCode = key;
                    data.eventCallbackFn(e);
                }
            }
        );


        glfwSetCursorPosCallback(m_Handle, [](GLFWwindow* window, double xpos, double ypos)
            {
                WINDOW_CALLBACK_PREAMBLE
                MouseMovedEvent e;
                e.x = xpos;
                e.y = ypos;
                data.eventCallbackFn(e);
            }
        );

        glfwSetMouseButtonCallback(m_Handle, [](GLFWwindow* window, int button, int action, int mods)
            {
                WINDOW_CALLBACK_PREAMBLE
                if(action == GLFW_PRESS)
                {
                    MouseButtonPressedEvent e;
                    e.button = button;
                    data.eventCallbackFn(e);
                }
                else if (action == GLFW_RELEASE)
                {
                    MouseButtonReleasedEvent e;
                    e.button = button;
                    data.eventCallbackFn(e);
                }
            }
        );

        glfwSetWindowCloseCallback(m_Handle, [](GLFWwindow* window)
            {
                WINDOW_CALLBACK_PREAMBLE
                WindowCloseEvent e;
                data.eventCallbackFn(e);
            }
        );

        glfwSetScrollCallback(m_Handle, [] (GLFWwindow* window, double xoffset, double yoffset)
            {   
                WINDOW_CALLBACK_PREAMBLE
                MouseScrollEvent e;
                e.xOffset = xoffset;
                e.yOffset = yoffset;
                data.eventCallbackFn(e);
            }
        );
    }

    WindowsWindow::~WindowsWindow()
    {
        if(m_Handle)
            glfwDestroyWindow(m_Handle);
    }

    double WindowsWindow::GetTimer()
    {
        return glfwGetTime();
    }
    void WindowsWindow::Update()
    {
        glfwSwapBuffers(m_Handle);
        glfwPollEvents();
    }
}