#include "LayerStack.h"

namespace Helios 
{
    LayerStack::LayerStack()
    {

    }

    LayerStack::~LayerStack()
    {
     	for (Layer *layer : m_Layers)
			delete layer;   
    }

    void LayerStack::AddLayer(Layer* layer)
    {
        m_Layers.emplace(m_Layers.begin() + m_LayerCursor++, layer);
    }

    void LayerStack::AddOverlay(Layer* layer)
    {
        m_Layers.emplace_back(layer);
    }

    void LayerStack::RemoveLayer(Layer* layer)
    {
        auto it = std::find(m_Layers.begin() , m_Layers.begin() + m_LayerCursor, layer);
        if (it != m_Layers.end())
        {
            m_Layers.erase(it);
            m_LayerCursor--;
        }
    }

    void LayerStack::RemoveOverlay(Layer* layer)
    {
        auto it = std::find(m_Layers.begin() + m_LayerCursor , m_Layers.end(), layer);
        if (it != m_Layers.end())
            m_Layers.erase(it);
    }
}