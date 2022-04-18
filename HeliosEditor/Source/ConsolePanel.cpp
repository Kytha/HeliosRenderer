#include "Panel.h"
#include "imgui.h"

namespace Helios
{
    ConsolePanel::ConsolePanel()
    {

    }

    ConsolePanel::~ConsolePanel()
    {
    }

    void ConsolePanel::Render()
    {
        ImGui::Begin("Console");
        ImGui::Text("Console");
        ImGui::End();
    }

}