#include "Window.h"

namespace Helios 
{
    Window::Window(WindowProps props) : m_Name(props.name), m_Height(props.height), m_Width(props.width), m_EventCallbackFn(props.eventCallbackFn) {}

    Window::~Window()
    {
        
    }
}