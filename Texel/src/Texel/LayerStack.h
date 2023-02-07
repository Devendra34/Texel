#ifndef LAYER_STACK_H
#define LAYER_STACK_H

#include "Texel/Core.h"
#include "Layer.h"

namespace Texel
{
    class TEXEL_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
        void PopLayer(Layer *layer);
        void PopOverlay(Layer *overlay);

        std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer *>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer *> m_Layers;
        std::vector<Layer *>::iterator m_LayerInsert;
    };
} // namespace Texel

#endif