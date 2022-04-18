#pragma once
#include "Core.h"
#include "Window.h"
#include <string>
#include "Events/Event.h"
#include "Core/LayerStack.h"
#include "UI/ImGuiContext.h"

namespace Helios 
{
    class Application
    {
    public:
        Application(const std::string& name);
        virtual ~Application();
        void OnEvent(Event& e);
        bool OnWindowClose(WindowCloseEvent event);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        void Run();
        void Close() { m_IsRunning = false; }
        inline Window& GetWindow() {return *m_Window;};
        inline std::string& GetName() {return m_Name;};
    private:
        std::string m_Name;
        bool m_IsRunning = true;
        Window* m_Window;
        double m_PreviousFrameTime;
        LayerStack m_LayerStack;
        ImGuiContext m_ImGuiContext;
    };
}