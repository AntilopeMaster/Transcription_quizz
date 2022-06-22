#include "include/Module.h"
#include "include/utils.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

Module::Module ( std::string filePath, std::string moduleName ) :
    m_filePath ( filePath ),
    m_moduleName ( moduleName )
{
    filePath = std::regex_replace ( filePath, std::regex ( "file://" ), "" );
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
    }
    else
    {
        std::cerr << "Unable to open file : " << filePath << '\n';
        return;
    }

    std::cout << m_moduleName << std::endl;

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

std::vector<std::string> Module::keys() const
{
    std::vector<std::string> ret;
    ret.resize ( m_translations_map.size() );

    std::transform ( m_translations_map.cbegin(), m_translations_map.cend(), ret.begin(), [] ( const auto & p )
    {
        return p.first;
    } );

    return ret;
}

std::vector<std::string> Module::values() const
{
    std::vector<std::string> ret;
    ret.resize ( m_translations_map.size() );

    std::transform ( m_translations_map.cbegin(), m_translations_map.cend(), ret.begin(), [] ( const auto & p )
    {
        return p.second;
    } );

    return ret;
}
