#ifndef Application_h
#define Application_h

#include "Core.h"
#include "Events/Event.h"

namespace Texel {
    class TEXEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };
    
    // To be defined in Client
    Application* CreateApplication();
}

#endif