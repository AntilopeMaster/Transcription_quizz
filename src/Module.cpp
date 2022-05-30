#include "include/Module.h"
#include "include/utils.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

Module::Module ( std::string filePath, std::string moduleName ) :
    m_filePath ( filePath ),
    m_moduleName ( moduleName )
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
//        print_map ( m_translations_map );
    }
    else
    {
        std::cerr << "Unable to open file : " << filePath << '\n';
    }

    if ( !moduleName.empty() )
    {
        m_moduleName = moduleName;
    }
    else
    {
        m_moduleName = split ( split ( filePath, '/' ).back(), '.' ).front();
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

std::string Module::filePath() const
{
    return m_filePath;
}

std::string Module::moduleName() const
{
    return m_moduleName;
}

std::list<std::string> Module::keys() const
{
    std::list<std::string> ret;

    std::for_each ( m_translations_map.cbegin(), m_translations_map.cend(), [&ret] ( const std::pair<std::string, std::string> map_element )
    {
        ret.push_back ( map_element.first );
    } );

    return ret;
}

std::list<std::string> Module::values() const
{
    std::list<std::string> ret;
    std::for_each ( m_translations_map.cbegin(), m_translations_map.cend(), [&ret] ( const std::pair<std::string, std::string> map_element )
    {
        ret.push_back ( map_element.second );
    } );

    return ret;
}
