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

    void Application::OnEvent(Event &e)
    {
        TEXEL_CORE_INFO("{0}", e);
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
    }

    Application::~Application() {}

    void Application::Run()
    {
         while (m_Running)
         {
            m_Window->OnUpdate();
         }
         
    }

    bool Application::OnWindowClose(WindowCloseEvent &event)
    {
        m_Running = false;
        return true;
    }

} // namespace Texel
