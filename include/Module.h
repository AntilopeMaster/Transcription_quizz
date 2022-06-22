#pragma once

#include <string>
#include <map>
#include <vector>

class Module
{

public:
    Module ( std::string filePath, std::string moduleName = "" );

    std::string key ( std::string value ) const;

    std::string filePath() const;
    std::string moduleName() const;

    std::vector<std::string> keys() const;

    std::vector<std::string> values() const;

protected:
    std::map<std::string, std::string> m_translations_map;

    std::string m_filePath;
    std::string m_moduleName;
};
