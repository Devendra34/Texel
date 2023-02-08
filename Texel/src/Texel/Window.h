#ifndef Window_h
#define Window_h

#include "texel_pch.h"

#include "Texel/Core.h"
#include "Texel/Events/Event.h"

namespace Texel
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(
            const std::string &title = "Texel Engine",
            const unsigned int &width = 1280,
            const unsigned int &height = 720) : Title(title), Width(width), Height(height) {}
    };

    // Interface representing a desktop system based Window
    class TEXEL_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event &)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

        static Window *Create(const WindowProps &props = WindowProps());
    };

} // namespace Texel

#endif