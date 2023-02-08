#include <Texel.h>

class Sandbox : public Texel::Application
{
public:
    Sandbox()
    {
        TEXEL_INFO("Creating Sandbox");
        auto imGuiLayer = new Texel::ImGuiLayer();
        PushOverlay(imGuiLayer);
    }
    ~Sandbox()
    {
    }
};

Texel::Application *Texel::CreateApplication()
{
    return new Sandbox();
}