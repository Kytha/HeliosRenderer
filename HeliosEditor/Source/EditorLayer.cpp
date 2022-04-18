#include "EditorLayer.h"
#include "HeliosEditor.h"
#include "Panel.h"
#include "Core/OperatingSystem.h"
#include "iostream"
#include "UI/Core.h"
#include "glm/glm.hpp"

namespace Helios
{
    EditorLayer::EditorLayer()
    {
        m_Panels.push_back(new InspectorPanel());
        m_Panels.push_back(new EnvironmentPanel());
        m_Panels.push_back(new SceneHierarchyPanel());
        m_Panels.push_back(new AssetBrowserPanel());
        m_Panels.push_back(new ConsolePanel());
    }

    EditorLayer::~EditorLayer()
    {
        for (auto panel : m_Panels)
        {
            delete panel;
        }
    }

    void EditorLayer::OnUIRender()
    {
        static bool show = true;
        static bool opt_fullscreen = true;
        static bool opt_padding = false;
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
        // because it would be confusing to have two docking targets within each others.
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        if (opt_fullscreen)
        {
            const ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
            window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        }
        else
        {
            dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
        }

        if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
            window_flags |= ImGuiWindowFlags_NoBackground;

        if (!opt_padding)
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("DockSpace", &show, window_flags);
        if (!opt_padding)
            ImGui::PopStyleVar();

        if (opt_fullscreen)
            ImGui::PopStyleVar(2);

        // Submit the DockSpace
        ImGuiIO& io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspace_id = ImGui::GetID("DockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
        }
        bool openRenderDialog = false;

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {  
                if (ImGui::MenuItem("New", "Ctrl+N"))
                {
                
                }
                if (ImGui::MenuItem("Open", "Ctrl+O"))
                {
                }

                if (ImGui::MenuItem("Save", "Ctrl+S"))
                {
                }

                if (ImGui::MenuItem("Save As", "Ctrl+Shift+S"))
                {
                }

                if (ImGui::MenuItem("Render", "Ctrl+R"))
                {
                    openRenderDialog = true;
                }

                if (ImGui::MenuItem("Exit"))
                {
                    OS::GetApplication(APPLICATION_NAME).Close();
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Edit"))
            {  
                if (ImGui::MenuItem("Undo", "Ctrl+Z", false, false)) {}
                if (ImGui::MenuItem("Redo", "Ctrl+Y", false, false)) {}  // Disabled item"))
                ImGui::Separator();
                if (ImGui::MenuItem("Duplicate", "Ctrl+D"))
                {
            
                }

                if (ImGui::MenuItem("Lock", "Ctrl+L"))
                {
            
                }

                if (ImGui::MenuItem("Hide", "Ctrl+H"))
                {
            
                }
                ImGui::Separator();
                if (ImGui::MenuItem("Delete", "Ctrl+X"))
                {
            
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("View"))
            {  
                if (ImGui::MenuItem("Show All Light Sources"))
                {
            
                }
                if (ImGui::MenuItem("Light"))
                {
            
                }
                if (ImGui::MenuItem("Wireframe"))
                {
            
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Window"))
            {  
                if (ImGui::MenuItem("Inspector"))
                {
            
                }
                if (ImGui::MenuItem("Environment"))
                {
            
                }
                if (ImGui::MenuItem("Scene Hierarchy"))
                {
            
                }
                if (ImGui::MenuItem("Asset Browser"))
                {
            
                }
                if (ImGui::MenuItem("Console"))
                {
            
                }
                if (ImGui::MenuItem("System Info"))
                {
            
                }
                if (ImGui::MenuItem("Render Stats"))
                {
                    
                }
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("Preferences"))
            {  
                
            }
            if (ImGui::BeginMenu("Help"))
            {  
                if (ImGui::MenuItem("About Helios Engine"))
                {
            
                }
                if (ImGui::MenuItem("Beginner's Guide"))
                {
                    
                }
                if (ImGui::MenuItem("Official Docs"))
                {
                    OS::OpenURL("https://HeliosRenderer.github.io/");
                }
                if (ImGui::MenuItem("Report an Issue"))
                {
            
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
        if (openRenderDialog)
        {
            ImGui::OpenPopup("Render Settings");
        }

        ImGui::SetNextWindowSize(ImVec2(800, 400), ImGuiCond_FirstUseEver || ImGuiCond_Appearing);
        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));         
        if (ImGui::BeginPopupModal("Render Settings", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse))
        {
            UI::BeginPropertyGrid();
            UI::Property("Test", glm::vec3(1.0f, 0.0f, 0.0f));
            UI::EndPropertyGrid();
            ImGui::Separator();
    

            ImGui::ProgressBar(0.5, ImVec2(-1,5), "");
            

            if (ImGui::Button("Render", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
            ImGui::SetItemDefaultFocus();
            ImGui::SameLine();
            if (ImGui::Button("Cancel", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
            ImGui::EndPopup();
        }
        ImGui::End();

        for (auto panel : m_Panels)
        {
            panel->Render();
        }
    }

    void EditorLayer::OnAttach()
    {

    }

    void EditorLayer::OnDetach()
    {

    }

    void EditorLayer::OnUpdate(double dt)
    {

    }

    void EditorLayer::OnEvent(Event& event)
    {

    }
}