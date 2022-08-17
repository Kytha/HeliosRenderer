#include "Helios.h"
#include "Panel.h"

namespace Helios
{
    InspectorPanel::InspectorPanel()
    {

    }

    InspectorPanel::~InspectorPanel()
    {
    }

    void InspectorPanel::Render()
    {
        ImGui::Begin(ICON_FA_CUBES " Inspector");
        ImGui::Text("Inspector");
        ImGui::End();
    }

}
