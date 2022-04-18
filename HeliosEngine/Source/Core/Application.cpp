#include "Application.h"
#include "OperatingSystem.h"
#include <iostream>
#include "Core/Events/KeyCodes.h"
#include "imgui.h"
#include <glad/glad.h>

#define BIND_FN(fn) [this](auto &&...args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...);}

namespace Helios
{
    Application::Application(const std::string& name) : m_Name(name)   
    {
        WindowProps props = {name, 1920, 1080, BIND_FN(OnEvent)};
        m_Window = OS::CreateWindow(props);
        m_ImGuiContext.Initialize(*m_Window);
    }

    Application::~Application()
    {
        m_ImGuiContext.Finalize();
        delete m_Window;
    }

    bool Application::OnWindowClose(WindowCloseEvent event)
    {
        m_IsRunning = false;
        return true;
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(&e);
        dispatcher.On<WindowCloseEvent>(BIND_FN(OnWindowClose));
        if(e.handled != true)
        {
            for(Layer* layer : m_LayerStack)
            {
                layer->OnEvent(e);
            }
        }
    }

    void Application::Run()
    {
        while(m_IsRunning)
        {
            double currentTime = m_Window->GetTimer();
            double delta = m_Window->GetTimer() - m_PreviousFrameTime;
            m_PreviousFrameTime = currentTime;
        
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
            for(Layer* layer : m_LayerStack)
            {
                layer->OnUpdate(delta);
            }

            m_ImGuiContext.Begin();
            for(Layer* layer : m_LayerStack)
            {
                layer->OnUIRender();
            }
            m_ImGuiContext.End(*m_Window);
            m_Window->Update();
        }
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.AddLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.AddOverlay(layer);
        layer->OnAttach();
    }
}