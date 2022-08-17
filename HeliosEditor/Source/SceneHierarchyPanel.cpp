#include "Helios.h"
#include "Panel.h"

namespace Helios
{
    SceneHierarchyPanel::SceneHierarchyPanel()
    {

    }

    SceneHierarchyPanel::~SceneHierarchyPanel()
    {
    }

    void SceneHierarchyPanel::Render()
    {
        ImGui::Begin(ICON_FA_SITEMAP " Scene Hierarchy");
        ImGui::Text("Scene Hierarchy");
        ImGui::End();
    }

}
