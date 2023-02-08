#ifndef Application_h
#define Application_h

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace Texel
{
    class TEXEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &event);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *layer);

        inline Window &GetWindow() const { return *m_Window; }

        inline static Application &Get() { return *m_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

    private:
        static Application *m_Instance;
    };

    // To be defined in Client
    Application *CreateApplication();
}

#endif