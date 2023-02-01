#ifndef EntryPoint_h
#define EntryPoint_h

#include <stdio.h>

namespace Texel
{
    extern Application *CreateApplication();
}

int main(int argc, char **argv)
{
    Texel::Application *app = Texel::CreateApplication();
    printf("Hello Texel Engine\n");
    app->Run();
    delete app;
    return 0;
}

#endif