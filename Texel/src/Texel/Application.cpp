#include "texel_pch.h"
#include "Application.h"

#include <GLFW/glfw3.h>
#include "Texel/Events/ApplicationEvent.h"
#include "Texel/Log.h"

namespace Texel
{

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application() {}

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *layer)
    {
        m_LayerStack.PushOverlay(layer);
    } 

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.IsHandled())
                break;
        }
    }

    void Application::Run()
    {
        while (m_Running)
        {
            for (auto layer : m_LayerStack) {
                layer->OnUpdate();
            }
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &event)
    {
        m_Running = false;
        return true;
    }

} // namespace Texel
