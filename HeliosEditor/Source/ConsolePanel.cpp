#include "Helios.h"
#include "Panel.h"


namespace Helios
{
    ConsolePanel::ConsolePanel()
    {
        m_Console = std::make_shared<ConsoleComponent>();
        Log::GetCoreLogger()->sinks().push_back(m_Console);
        spdlog::set_pattern("%^[%l]: %v%$");
    }

    ConsolePanel::~ConsolePanel()
    {
    }

    void ConsolePanel::Render()
    {
        ImGui::Begin(ICON_FA_TERMINAL " Console");
        m_Console->OnRender();
        ImGui::End();
    }

}