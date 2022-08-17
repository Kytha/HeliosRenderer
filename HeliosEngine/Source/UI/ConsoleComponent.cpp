#pragma once
#include "Core/Log.h"
#include "imgui.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/base_sink.h"
#include "ConsoleComponent.h"
#include "UI/Colours.h"

namespace Helios
{
    ConsoleComponent::ConsoleComponent() 
    {
        ClearLog();
        memset(InputBuf, 0, sizeof(InputBuf));
        HistoryPos = -1;
        AutoScroll = true;
        ScrollToBottom = false;
    };

    ConsoleComponent::~ConsoleComponent() 
    {
        ClearLog();
        for (int i = 0; i < History.Size; i++)
            free(History[i]);
    };

    void ConsoleComponent::ClearLog()
    {
        for (int i = 0; i < Items.Size; i++)
            free(Items[i].text);
        Items.clear();
    }

    ImVec4 LevelToColor(int level)
    {
        switch (level)
        {
            case SPDLOG_LEVEL_TRACE: return Colours::trace;
            case SPDLOG_LEVEL_DEBUG: return Colours::debug;
            case SPDLOG_LEVEL_INFO: return Colours::info;
            case SPDLOG_LEVEL_WARN: return Colours::warn;
            case SPDLOG_LEVEL_ERROR: return Colours::error;
            case SPDLOG_LEVEL_CRITICAL: return Colours::critical;
            default: return Colours::text;
        }
    }
    void ConsoleComponent::AddLog(const char* fmt, int level  ...)
    {
        char buf[1024];
        va_list args;
        va_start(args, fmt);
        vsnprintf(buf, IM_ARRAYSIZE(buf), fmt, args);
        buf[IM_ARRAYSIZE(buf)-1] = 0;
        va_end(args);
        Items.push_back({Strdup(buf), level});
    }

    void ConsoleComponent::OnRender()
    {
        // As a specific feature guaranteed by the library, after calling Begin() the last Item represent the title bar.
        // So e.g. IsItemHovered() will return true when hovering the title bar.
        // Here we create a context menu only available from the title bar.

        // TODO: display items starting from the bottom
        if (ImGui::SmallButton("Clear"))           { ClearLog(); }
        ImGui::SameLine();
        bool copy_to_clipboard = ImGui::SmallButton("Copy");
        //static float t = 0.0f; if (ImGui::GetTime() - t > 0.02f) { t = ImGui::GetTime(); AddLog("Spam %f", t); }

        ImGui::Separator();

        // Options menu
        if (ImGui::BeginPopup("Options"))
        {
            ImGui::Checkbox("Auto-scroll", &AutoScroll);
            ImGui::EndPopup();
        }

        // Options, Filter
        if (ImGui::Button("Options"))
            ImGui::OpenPopup("Options");
        ImGui::SameLine();
        Filter.Draw("Filter (\"incl,-excl\") (\"error\")", 180);
        ImGui::Separator();

        // Reserve enough left-over height for 1 separator + 1 input text
        const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();
        ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar);
        if (ImGui::BeginPopupContextWindow())
        {
            if (ImGui::Selectable("Clear")) ClearLog();
            ImGui::EndPopup();
        }

        // Display every line as a separate entry so we can change their color or add custom widgets.
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1)); // Tighten spacing
        if (copy_to_clipboard)
            ImGui::LogToClipboard();
        for (int i = 0; i < Items.Size; i++)
        {
            const char* text = Items[i].text;

            if (!Filter.PassFilter(text))
                continue;

            // Normally you would store more information in your item than just a string.
            // (e.g. make Items[] an array of structure, store color/type etc.)

            ImGui::PushStyleColor(ImGuiCol_Text, LevelToColor(Items[i].level));
            ImGui::TextUnformatted(text);
            ImGui::PopStyleColor();
        }
        if (copy_to_clipboard)
            ImGui::LogFinish();

        if (ScrollToBottom || (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
            ImGui::SetScrollHereY(1.0f);
        ScrollToBottom = false;

        ImGui::PopStyleVar();
        ImGui::EndChild();
        ImGui::Separator();

        // Command-line
        /*
        bool reclaim_focus = false;
        ImGuiInputTextFlags input_text_flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory;
        if (ImGui::InputText("Input", InputBuf, IM_ARRAYSIZE(InputBuf), input_text_flags, &TextEditCallbackStub, (void*)this))
        {
            char* s = InputBuf;
            Strtrim(s);
            if (s[0])
                ExecCommand(s);
            strcpy(s, "");
            reclaim_focus = true;
        }
        
        // Auto-focus on window apparition
        ImGui::SetItemDefaultFocus();
        if (reclaim_focus)
            ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget
        */
    }

    void ConsoleComponent::sink_it_(const spdlog::details::log_msg& msg)
    {
        spdlog::memory_buf_t formatted;
        spdlog::sinks::base_sink<spdlog::details::null_mutex>::formatter_->format(msg, formatted);
        AddLog(fmt::to_string(formatted).c_str(), msg.level);
    }

    void ConsoleComponent::flush_()
    {
        ClearLog();
    }
}


