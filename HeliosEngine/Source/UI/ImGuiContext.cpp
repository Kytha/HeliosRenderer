#include "ImGuiContext.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>


#define BACKGROUND_COLOR rgbUint8ToFloat(23,26,33);
#define BACKGROUND_COLOR_HIGHLIGHT ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
#define BACKGROUND_COLOR_ACTIVE ImVec4(0.3f, 0.3f, 0.3f, 1.0f);

ImVec4 rgbUint8ToFloat(int r, int g, int b)
{
    return ImVec4(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
}

namespace Helios
{

    ImGuiContext::ImGuiContext()
    {

    }
    ImGuiContext::~ImGuiContext()
    {

    }
    void ImGuiContext::Initialize(Window& window)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;        // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;	        // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

        float fontSize = 16.0f;
        //io.Fonts->AddFontFromFileTTF("Assets/Fonts/Roboto/Roboto-Regular.ttf", fontSize);
        io.FontDefault = io.Fonts->AddFontFromFileTTF("Assets/Fonts/Roboto/Roboto-Regular.ttf", fontSize);

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        SetStyles();
        ImGuiStyle &style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }
        
        GLFWwindow *win = static_cast<GLFWwindow *>(window.GetNativeWindow());

        // Setup Platform/Renderer bindings
        ImGui_ImplGlfw_InitForOpenGL(win, true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiContext::Finalize()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiContext::Begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }
    void ImGuiContext::End(Window& window)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.DisplaySize = ImVec2((float)window.GetWidth(), (float)window.GetHeight());

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    };


    
    void ImGuiContext::SetStyles()
    {
        ImGuiStyle* style = &ImGui::GetStyle();
        ImVec4* colors = style->Colors;

        colors[ImGuiCol_Text] = rgbUint8ToFloat(235, 235, 235);
        colors[ImGuiCol_TextDisabled] = ImVec4(0.500f, 0.500f, 0.500f, 1.000f);
        colors[ImGuiCol_WindowBg] = rgbUint8ToFloat(23,26,33);
        colors[ImGuiCol_ChildBg] = ImVec4(0.280f, 0.280f, 0.280f, 0.000f);
        colors[ImGuiCol_PopupBg] = rgbUint8ToFloat(13,16,23);
        colors[ImGuiCol_Border] = rgbUint8ToFloat(23,26,33);
        colors[ImGuiCol_BorderShadow] = ImVec4(0.000f, 0.000f, 0.000f, 0.000f);
        colors[ImGuiCol_FrameBg] = rgbUint8ToFloat(32,35,43);
        colors[ImGuiCol_FrameBgHovered] = rgbUint8ToFloat(52,55,63);
        colors[ImGuiCol_FrameBgActive] = rgbUint8ToFloat(42,45,53);
        colors[ImGuiCol_TitleBg] = rgbUint8ToFloat(13, 16, 23);
        colors[ImGuiCol_TitleBgActive] = rgbUint8ToFloat(13, 16, 23);
        colors[ImGuiCol_TitleBgCollapsed] = rgbUint8ToFloat(13, 16, 23);
        colors[ImGuiCol_MenuBarBg] = rgbUint8ToFloat(13, 16, 23);
        colors[ImGuiCol_ScrollbarBg] = rgbUint8ToFloat(23,26,33);
        colors[ImGuiCol_ScrollbarGrab] =  rgbUint8ToFloat(72,75,83);
        colors[ImGuiCol_ScrollbarGrabHovered] =  rgbUint8ToFloat(82,85,93);
        colors[ImGuiCol_ScrollbarGrabActive] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_CheckMark] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_SliderGrab] = rgbUint8ToFloat(72,75,83);
        colors[ImGuiCol_SliderGrabActive] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_Button] = ImVec4(1.000f, 1.000f, 1.000f, 0.000f);
        colors[ImGuiCol_ButtonHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
        colors[ImGuiCol_ButtonActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.391f);
        colors[ImGuiCol_Header] = rgbUint8ToFloat(32,35,43);
        colors[ImGuiCol_HeaderHovered] = rgbUint8ToFloat(52,55,63);
        colors[ImGuiCol_HeaderActive] = rgbUint8ToFloat(42,45,53);
        colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
        colors[ImGuiCol_SeparatorHovered] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
        colors[ImGuiCol_SeparatorActive] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_ResizeGrip] = ImVec4(1.000f, 1.000f, 1.000f, 0.250f);
        colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.670f);
        colors[ImGuiCol_ResizeGripActive] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_Tab] = rgbUint8ToFloat(17, 20, 25);
        colors[ImGuiCol_TabHovered] = rgbUint8ToFloat(53, 56, 65);
        colors[ImGuiCol_TabActive] = rgbUint8ToFloat(43, 46, 55);
        colors[ImGuiCol_TabUnfocused] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
        colors[ImGuiCol_TabUnfocusedActive] = rgbUint8ToFloat(43, 46, 55);
        colors[ImGuiCol_DockingPreview] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_DockingEmptyBg] = rgbUint8ToFloat(42,45,53);
        colors[ImGuiCol_PlotLines] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
        colors[ImGuiCol_PlotLinesHovered] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_PlotHistogram] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_PlotHistogramHovered] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_TextSelectedBg] = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
        colors[ImGuiCol_DragDropTarget] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_NavHighlight] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_NavWindowingHighlight] = rgbUint8ToFloat(219, 39, 119);
        colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);
        colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);

        style->ChildRounding = 4.0f;
        style->FrameBorderSize = 0.0f;
        style->FrameRounding = 3.0f;
        style->GrabMinSize = 7.0f;
        style->PopupRounding = 2.0f;
        style->ScrollbarRounding = 12.0f;
        style->ScrollbarSize = 10.0f;
        style->TabBorderSize = 1.0f;
        style->TabRounding = 3.0f;
        style->WindowRounding = 4.0f;
        style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
        style->WindowMenuButtonPosition = ImGuiDir_Right;
        style->ColorButtonPosition = ImGuiDir_Right;
        style->FramePadding = ImVec2(9.0f, 4.0f);
        style->ItemSpacing = ImVec2(10.0f, 10.0f);
        style->ItemInnerSpacing = ImVec2(4.0f, 4.0f);
        style->TouchExtraPadding = ImVec2(0.0f, 0.0f);
        style->IndentSpacing = 21.0f;
        style->ColumnsMinSpacing = 50.0f;
        style->TabBorderSize = 0.0f;
    }
}