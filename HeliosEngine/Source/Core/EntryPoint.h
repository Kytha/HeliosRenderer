#pragma once

#include "Core.h"
#include "OperatingSystem.h"

#if PLATFORM == PLATFORM_WINDOWS
    #include "Windows.h"
    #define APPLICATION_ENTRY(ApplicationClass, ...)                                                                                        \
    int main(int argc, const char** argv) { Helios::Log::Init(); Helios::OS::CreateApplication<ApplicationClass>(__VA_ARGS__); Helios::OS::Run(); }                               \
    int APIENTRY wWinmain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) { return main(__argc, (const char **) __argv);}
#elif PLATFORM == PLATFORM_LINUX
    #define APPLICATION_ENTRY(ApplicationClass, ...)                                                        \
    int main(int argc, const char** argv) { Helios::Log::Init(); Helios::OS::CreateApplication<ApplicationClass>(__VA_ARGS__); Helios::OS::Run(); } 
#endif


