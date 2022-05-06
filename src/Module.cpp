#include "include/Module.h"
#include "include/utils.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

Module::Module ( std::string filePath, std::string moduleName )
{
    std::string line;
    std::ifstream file ( filePath );

    if ( file.is_open() )
    {
        while ( std::getline ( file, line ) )
        {
            std::vector<std::string> splitted = split ( line, ' ' );
            m_translations_map[splitted[1]] = splitted[0];
        }

        file.close();
        print_map ( m_translations_map );

    }
    else
    {
        std::cerr << "Unable to open file : " << filePath << '\n';
    }
}

std::string Module::key ( std::string value ) const
{
    auto it = std::find_if ( m_translations_map.cbegin(), m_translations_map.cend(), [&value] ( const std::pair<std::string, std::string> map_element )
    {
        return map_element.second == value;
    } );

    return it->first;
}

std::string Module::moduleName() const
{
    return m_moduleName;
}
