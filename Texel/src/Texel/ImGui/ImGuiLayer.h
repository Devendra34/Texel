#ifndef IMGUI_LAYER_H
#define IMGUI_LAYER_H

#include "Texel/Layer.h"

#include "Texel/Events/ApplicationEvent.h"
#include "Texel/Events/KeyEvent.h"
#include "Texel/Events/MouseEvent.h"

namespace Texel
{
    class TEXEL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override;

        void OnAttach() override;
        void OnDetach() override;
        void OnImGuiRender() override;

        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };
} // namespace Texel

#endif