#include "Panel.h"
#include "imgui.h"

namespace Helios
{
    AssetBrowserPanel::AssetBrowserPanel()
    {

    }

    AssetBrowserPanel::~AssetBrowserPanel()
    {
    }

    void AssetBrowserPanel::Render()
    {
        ImGui::Begin("Asset Browser");
        ImGui::Text("Asset Browser");
        ImGui::End();
    }

}