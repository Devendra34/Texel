#include <Texel.h>

class Sandbox : public Texel::Application
{
public:
    Sandbox()
    {
    }
    ~Sandbox()
    {
    }
};

Texel::Application *Texel::CreateApplication()
{
    return new Sandbox();
}