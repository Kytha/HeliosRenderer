#pragma once
#include <functional>
#include <iostream>

#define EVENT_TYPE(x) static EventType GetStaticEventType() {return EventType::x;}    \
EventType GetEventType() const override { return GetStaticEventType();}                         \

namespace Helios
{
    enum class EventType
    {
        NONE,
        KEY_PRESSED,
        KEY_RELEASED,
        MOUSE_MOVE,
        MOUSE_BUTTON_PRESSED,
        MOUSE_BUTTON_RELEASED,
        WINDOW_CLOSE_EVENT,
        WINDOW_RESIZE_EVENT,
        MOUSE_SCROLL_EVENT
    };

    class Event
    {
    public:
        bool handled = false;
        virtual EventType GetEventType() const = 0;
    };

    class KeyPressedEvent : public Event
    {
    public:
        int keyCode;
        EVENT_TYPE(KEY_PRESSED)
    };

    class KeyReleasedEvent : public Event
    {
    public:
        int keyCode;
        EVENT_TYPE(KEY_RELEASED)
    };

    class MouseMovedEvent : public Event
    {
    public:
        double x,y;
        EVENT_TYPE(MOUSE_MOVE)
    };

    class MouseButtonPressedEvent : public Event
    {
    public:
        int button;
        EVENT_TYPE(MOUSE_BUTTON_PRESSED)
    };

    class MouseButtonReleasedEvent : public Event
    {
    public:
        int button;
        EVENT_TYPE(MOUSE_BUTTON_RELEASED)
    };

    class MouseScrollEvent : public Event
    {
    public:
        double xOffset;
        double yOffset;
        EVENT_TYPE(MOUSE_SCROLL_EVENT)
    };

    class WindowCloseEvent : public Event
    {
    public:
        EVENT_TYPE(WINDOW_CLOSE_EVENT)
    };

    class WindowResizeEvent : public Event
    {
    public:
        EVENT_TYPE(WINDOW_RESIZE_EVENT)
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event* e)
        {
            m_Event = e;
        }

        template<typename E>
        void On(const std::function<bool(E)>& fn)
        {
            if(m_Event->GetEventType() == E::GetStaticEventType())
                m_Event->handled = fn(static_cast<E&>(*m_Event));
        }
    private:
        Event* m_Event;
    };
}