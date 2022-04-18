#pragma once

#include "Core.h"
#include "OperatingSystem.h"

#if PLATFORM == PLATFORM_WINDOWS
    #define APPLICATION_ENTRY(ApplicationClass, ...)                                                        \
    int main(int argc, const char** argv) { Helios::OS::CreateApplication<ApplicationClass>(__VA_ARGS__);Helios::OS::GetOS().Run(); } 
#elif PLATFORM == PLATFORM_LINUX
    #define APPLICATION_ENTRY(ApplicationClass, ...)                                                        \
    int main(int argc, const char** argv) { OS::CreateApplication<ApplicationClass>(__VA_ARGS__);OS::Run(); } 
#endif