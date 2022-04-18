#include "Helios.h"
#include "HeliosEditor.h"
#include "EditorLayer.h"

class MyApplication : public Helios::Application
{
public:
    MyApplication(const std::string& name) : Application(name) 
    {
        PushLayer(new Helios::EditorLayer());
    }
};

APPLICATION_ENTRY(MyApplication, APPLICATION_NAME)