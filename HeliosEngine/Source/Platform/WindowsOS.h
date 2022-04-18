#pragma once
#include "Core/OperatingSystem.h"

namespace Helios 
{
    class WindowsOS : public OS
    {
    public:
        WindowsOS();
        ~WindowsOS();
        Window* CreateNativeWindow(WindowProps props) override;
        void NativeOpenURL(const std::string& url) override;
    };
}
