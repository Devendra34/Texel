#include <Texel.h>

class Sandbox : public Texel::Application
{
public:
    Sandbox()
    {
        TEXEL_INFO("Creating Sandbox");
    }
    ~Sandbox()
    {
    }
};

Texel::Application *Texel::CreateApplication()
{
    return new Sandbox();
}