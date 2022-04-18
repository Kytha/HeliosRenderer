#include "Panel.h"
#include "imgui.h"

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
        ImGui::Begin("Inspector");
        ImGui::Text("Inspector");
        ImGui::End();
    }

}
