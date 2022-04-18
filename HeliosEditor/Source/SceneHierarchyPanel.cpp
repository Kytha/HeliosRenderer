#include "Panel.h"
#include "imgui.h"

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
        ImGui::Begin("Scene Hierarchy");
        ImGui::Text("Scene Hierarchy");
        ImGui::End();
    }

}
