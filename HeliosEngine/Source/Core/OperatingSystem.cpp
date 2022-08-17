#include "OperatingSystem.h"
#include "Platform/WindowsOS.h"

#include "iostream"

namespace Helios
{
    OS* OS::s_Instance = nullptr;
    
    OS::OS()
    {

    }

    OS::~OS()
    {
        for(auto& app : m_Applications)
        {
            delete app.second;
        }
        m_Applications.clear();
    }

    void OS::Run()
    {
        for(auto& app : GetOS().m_Applications)
        {
            app.second->Run();
            delete app.second;
            GetOS().m_Applications.erase(app.first);
        }
    }
    
    OS& OS::GetOS()
    {
        if(s_Instance != nullptr)
            return *s_Instance;
        
        switch(PLATFORM)
        {
            case PLATFORM_WINDOWS:
                s_Instance = new WindowsOS();
                break;
            default:
                std::cout << "OS not supported!";
        }
        return *s_Instance;
    }

    void OS::OpenURL(const std::string& url)
    {
        GetOS().NativeOpenURL(url);
    }

    Application& OS::GetApplication(std::string name)
    {
        if(GetOS().m_Applications.find(name) != GetOS().m_Applications.end())
            return *GetOS().m_Applications[name];
        
        std::cout << "Application does not exist!";
    }

    Window* OS::CreateOSWindow(WindowProps props) {
        return GetOS().CreateNativeWindow(props);
    }
}