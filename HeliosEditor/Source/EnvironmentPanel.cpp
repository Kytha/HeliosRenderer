#include "Panel.h"
#include "imgui.h"

namespace Helios
{
    EnvironmentPanel::EnvironmentPanel()
    {

    }

    EnvironmentPanel::~EnvironmentPanel()
    {
    }

    void EnvironmentPanel::Render()
    {
        ImGui::Begin("Environment");
        ImGui::Text("Environment");
        ImGui::End();
    }

}