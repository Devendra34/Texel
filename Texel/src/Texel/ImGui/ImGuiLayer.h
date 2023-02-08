#ifndef IMGUI_LAYER_H
#define IMGUI_LAYER_H

#include "Texel/Layer.h"
#include "GLFW/glfw3.h"

namespace Texel
{
    class TEXEL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override;

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event &event) override;

    private:
        float m_Time = 0.0f;
    };
} // namespace Texel

#endif