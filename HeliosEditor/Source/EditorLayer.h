#include "Core/Layer.h"
#include "Core/Events/Event.h"
#include "Panel.h"
namespace Helios
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer();
        ~EditorLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;

        void OnUpdate(double dt) override;
        void OnUIRender() override;
        void OnEvent(Event& event) override;

        bool OnKeyPressed(KeyPressedEvent& event);
        bool OnKeyReleased(KeyReleasedEvent& event);
        bool OnMouseButtonPressed(MouseButtonPressedEvent& event);
        bool OnMouseButtonReleased(MouseButtonReleasedEvent& event);
        bool OnMouseMoved(MouseMovedEvent& event);
        bool OnWindowResize(WindowResizeEvent& event);
    private:
        std::vector<Panel*> m_Panels;
    };
}