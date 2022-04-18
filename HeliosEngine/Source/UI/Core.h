#pragma once
#include "imgui.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

namespace UI
{
    static uint32_t s_Counter = 0;
    static int s_ContextID = 0;
    static const char* GenerateID()
    {
        static char buffer[64];
        static int counter = 0;
        sprintf(buffer, "id_%d", s_Counter++);
        return buffer;
    }

    static void PushContextID()
    {
        ImGui::PushID(s_ContextID++);
        s_Counter = 0;
    }

    static void PopContextID()
    {
        ImGui::PopID();
        s_ContextID--;
    }

    static void Property(const char* label, bool& value)
    {
        ImGui::Checkbox(label, &value);
    }

    static void Property(const char* label, int& value)
    {
        ImGui::InputInt(label, &value);
    }

    static void Property(const char* label, float& value)
    {
        ImGui::InputFloat(label, &value);
    }

    static void Property(const char* label, glm::vec3& value, float delta = 0.1f)
    {
        ImGui::Text(label);
        ImGui::NextColumn();
        ImGui::PushItemWidth(-1);
        ImGui::DragFloat3(GenerateID(), glm::value_ptr(value), delta);
        ImGui::PopItemWidth();
        ImGui::NextColumn();
    }

    static void BeginPropertyGrid()
    {
        PushContextID();
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8.0f, 8.0f));
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4.0f, 4.0f));
		ImGui::Columns(2);
    }

    static void EndPropertyGrid()
    {
        ImGui::PopStyleVar(2);
        ImGui::Columns(1);
        PopContextID();
    }
}