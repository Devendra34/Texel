#ifndef EntryPoint_h
#define EntryPoint_h

namespace Texel
{
    extern Application *CreateApplication();
}

int main(int argc, char **argv)
{
    Texel::Log::Init();
    TEXEL_CORE_TRACE("Init");

    Texel::Application *app = Texel::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif