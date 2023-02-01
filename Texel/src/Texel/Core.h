#ifndef Core_h
#define Core_h

#ifdef TEXEL_PLATFORM_WINDOWS
    #ifdef TEXEL_BUILD_DLL
        #define TEXEL_API __declspec(dllexport)
    #else
        #define TEXEL_API __declspec(dllimport)
    #endif
#else
    // dummy assignment for other platforms
    #define TEXEL_API
#endif

#define BIT(x) (1 << x)

#endif // Core_h