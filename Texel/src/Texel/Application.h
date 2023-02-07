#ifndef Application_h
#define Application_h

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Texel {
    class TEXEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &event);

    private:
        bool OnWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
    
    // To be defined in Client
    Application* CreateApplication();
}

#endif