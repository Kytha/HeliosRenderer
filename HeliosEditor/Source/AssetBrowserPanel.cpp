#include "Helios.h"
#include "Panel.h"

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
        ImGui::Begin(ICON_FA_FOLDER_OPEN " Asset Browser");
        ImGui::Text("Asset Browser");
        ImGui::End();
    }

}