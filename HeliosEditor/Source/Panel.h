#pragma once
#include "UI/ConsoleComponent.h"

namespace Helios
{
    class Panel
    {
    public:
        Panel() = default;
        ~Panel() = default;
        virtual void Render() {}
    };
    
    class InspectorPanel : public Panel
    {
    public:
        InspectorPanel();
        virtual ~InspectorPanel();
        void Render() override;
    };

    class EnvironmentPanel : public Panel
    {
    public:
        EnvironmentPanel();
        virtual ~EnvironmentPanel();
        void Render() override;
    };

    class SceneHierarchyPanel : public Panel
    {
    public:
        SceneHierarchyPanel();
        virtual ~SceneHierarchyPanel();
        void Render() override;
    };

    class AssetBrowserPanel : public Panel
    {
    public:
        AssetBrowserPanel();
        virtual ~AssetBrowserPanel();
        void Render() override;
    };

    class ConsolePanel : public Panel
    {
    public:
        ConsolePanel();
        virtual ~ConsolePanel();
        void Render() override;
    private:
        std::shared_ptr<ConsoleComponent> m_Console; 
    };
}

