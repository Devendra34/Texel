#include "texel_pch.h"
#include "Application.h"

#include <glad/gl.h>
#include "Texel/Events/ApplicationEvent.h"
#include "Texel/Log.h"

namespace Texel
{

    Application* Application::m_Instance = nullptr;

    Application::Application()
    {
        TEXEL_CORE_ASSERT(!m_Instance, "Application already exists!");
        m_Instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(TEXEL_BIND_EVENT_FN(Application::OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
    }

    Application::~Application() {}

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    } 

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(TEXEL_BIND_EVENT_FN(Application::OnWindowClose));

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
            glClearColor(0.2f, 0.3f, 0.8f, 0.1f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            for (auto layer : m_LayerStack) {
                layer->OnUpdate();
            }

            m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			    layer->OnImGuiRender();
			m_ImGuiLayer->End();
            
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &event)
    {
        m_Running = false;
        return true;
    }

} // namespace Texel
