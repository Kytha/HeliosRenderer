#include "Layer.h"
#include <vector>

namespace Helios
{
    class LayerStack
    {
    public:
        LayerStack();
        virtual ~LayerStack();

        void AddLayer(Layer* layer);

        void RemoveLayer(Layer* layer);

        void AddOverlay(Layer* layer);

        void RemoveOverlay(Layer* layer);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer *>::iterator end() { return m_Layers.end(); } 

    private:
        std::vector<Layer*> m_Layers;
        uint16_t m_LayerCursor = 0; 
    };
}