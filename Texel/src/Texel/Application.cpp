#include "Application.h"

#include "Texel/Events/ApplicationEvent.h"
#include "Texel/Log.h"

namespace Texel
{
    Application::Application() {}

    Application::~Application() {}

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication))
        {
            TEXEL_TRACE(e);
        }
        if (e.IsInCategory(EventCategoryInput))
        {
            TEXEL_TRACE(e);
        }
        
        while (true);
    }
} // namespace Texel
