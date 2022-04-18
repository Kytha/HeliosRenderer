#pragma once
#include <string>
#include <vector>

#define APPLICATION_NAME "HeliosEditor"

namespace Helios
{
    struct Entity
    {
        Entity()
            : m_name("")
        {
        }

        Entity(const std::string& name)
            : m_name(name)
        {
        }

        std::string m_name;
    };


    struct Context
    {
        Context()
        {

        }
        std::vector<Entity*> selectionContext;
    };
}
