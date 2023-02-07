#include "texel_pch.h"
#include "Application.h"

#include <GLFW/glfw3.h>
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

        if (!glfwInit()) {
            TEXEL_CORE_ERROR("Unable to init GLFW");
            return;
        }
        auto window = glfwCreateWindow(1280, 720, "TexelApp", nullptr, nullptr);
        glfwMakeContextCurrent(window);
        
        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);

            glfwPollEvents();
        }
        glfwDestroyWindow(window);
        glfwTerminate();
    }
} // namespace Texel
