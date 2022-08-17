#include "Helios.h"
#include "Panel.h"

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
        ImGui::Begin(ICON_FA_SUN_O " Environment");
        ImGui::Text("Environment");
        ImGui::End();
    }

}