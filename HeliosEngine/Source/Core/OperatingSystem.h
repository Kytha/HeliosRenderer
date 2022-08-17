#pragma once
#include "Core.h"
#include "Application.h"
#include "Window.h"

namespace Helios
{
    class OS
    {
    public:
        OS();
        virtual ~OS();
        virtual Window* CreateNativeWindow(WindowProps props) = 0;
    public:
        static OS& GetOS();
        static Application& GetApplication(std::string name = "HeliosEngine");
        static void OpenURL(const std::string& url);

        template <typename ApplicationClass, typename... Args>
        static void CreateApplication(Args&&... arguments)
        {    
            auto app = new ApplicationClass(std::forward<Args>(arguments)...);    
            GetOS().m_Applications[app->GetName()] = app;
        }
        static Window* CreateOSWindow(WindowProps props);
        static void Run();
    public:
        virtual void NativeOpenURL(const std::string& url) = 0;
    private:
        static OS* s_Instance;
        std::unordered_map<std::string, Application*> m_Applications;
    };
}