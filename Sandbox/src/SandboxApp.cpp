#include <Texel.h>

#include "imgui/imgui.h"

class ExampleLayer : public Texel::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }
    void OnUpdate() override
    {
    }

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
    }

    void OnEvent(Texel::Event &event) override
    {
    }
};

class Sandbox : public Texel::Application
{
public:
    Sandbox()
    {
        TEXEL_INFO("Creating Sandbox");
        PushOverlay(new ExampleLayer());
    }
    ~Sandbox()
    {
    }
};

Texel::Application *Texel::CreateApplication()
{
    return new Sandbox();
}