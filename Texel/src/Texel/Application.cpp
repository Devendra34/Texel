#include "texel_pch.h"
#include "Application.h"

#include <GLFW/glfw3.h>
#include "Texel/Events/ApplicationEvent.h"
#include "Texel/Log.h"

namespace Texel
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application() {}

    void Application::Run()
    {
         while (m_Running)
         {
            m_Window->OnUpdate();
         }
         
    }
} // namespace Texel
