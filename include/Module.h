#pragma once

#include <string>
#include <map>

class Module
{

public:
    Module ( std::string filePath, std::string moduleName = "" );

    std::string key ( std::string value ) const;

    std::string moduleName() const;

private:
    std::map<std::string, std::string> m_translations_map;
    std::map<std::string, std::string> m_cleanable_translations_map;

    std::string m_moduleName;
};
