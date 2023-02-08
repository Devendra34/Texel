#include "texel_pch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "imgui_impl_opengl2.h"

#include "Texel/Events/KeyEvent.h"
#include "Texel/Events/MouseEvent.h"

#include "Texel/Application.h"

namespace Texel
{
    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

    ImGuiLayer::~ImGuiLayer() = default;

    void ImGuiLayer::OnAttach()
    {
        // Setup Dear ImGui context
        TEXEL_CORE_ASSERT(IMGUI_CHECKVERSION(), "Unable to check imgui version");
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGuiIO &io = ImGui::GetIO();
        (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;    // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableSetMousePos; // Enable Keyboard Controls
        
        ImGui_ImplOpenGL2_Init();
    }

    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL2_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO &io = ImGui::GetIO();
        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0 ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        Application &app = Application::Get();
        Window& window = app.GetWindow();
        io.DisplaySize = ImVec2(window.GetWidth(), window.GetHeight());

        int display_w = window.GetFrameBufferWidth();
        int display_h = window.GetFrameBufferHeight();
        int w = window.GetWidth();
        int h = window.GetHeight();
        if (w > 0 && h > 0)
        io.DisplayFramebufferScale = ImVec2((float)display_w / (float)w, (float)display_h / (float)h);

        ImGui_ImplOpenGL2_NewFrame();
        ImGui::NewFrame();

        static bool showDemo = true;
        ImGui::ShowDemoWindow(&showDemo);

        ImGui::Render();
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event &e)
    {
    }
} // namespace Texel
