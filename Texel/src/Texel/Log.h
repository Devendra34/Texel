#ifndef Log_h
#define Log_h

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

namespace Texel
{
    class TEXEL_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define TEXEL_CORE_TRACE(...)   ::Texel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TEXEL_CORE_INFO(...)    ::Texel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TEXEL_CORE_WARN(...)    ::Texel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TEXEL_CORE_ERROR(...)   ::Texel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TEXEL_CORE_FATAL(...)   ::Texel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TEXEL_TRACE(...)        ::Texel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TEXEL_INFO(...)         ::Texel::Log::GetClientLogger()->info(__VA_ARGS__)
#define TEXEL_WARN(...)         ::Texel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TEXEL_ERROR(...)        ::Texel::Log::GetClientLogger()->error(__VA_ARGS__)
#define TEXEL_FATAL(...)        ::Texel::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif