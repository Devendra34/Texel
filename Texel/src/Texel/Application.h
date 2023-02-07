#ifndef Application_h
#define Application_h

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Texel {
    class TEXEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
    
    // To be defined in Client
    Application* CreateApplication();
}

#endif