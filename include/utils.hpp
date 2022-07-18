#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <map>
#include <utility>
#include <list>
#include <iterator>

template <typename Out>
inline void split ( const std::string& s, char delim, Out result )
{
    std::istringstream iss ( s );
    std::string item;

    while ( std::getline ( iss, item, delim ) )
    {
        *result++ = item;
    }
}

inline std::vector<std::string> split ( const std::string& s, char delim )
{
    std::vector<std::string> elems;
    split ( s, delim, std::back_inserter ( elems ) );
    return elems;
}

template<typename T>
std::ostream& operator<< ( std::ostream& stream, const std::vector<T>& vec )
{
    for ( typename std::vector<T>::const_reference data : vec )
    {
        stream << data << '\n';
    }

    return stream;
}

template<typename T, typename S>
std::ostream& operator<< ( std::ostream& stream, const std::pair<T, S>& pair )
{
    stream << pair.first << " " << pair.second << '\n';
    return stream;
}


template<typename T>
std::ostream& operator<< ( std::ostream& stream, const std::list<T>& vec )
{
    for ( typename std::list<T>::const_reference data : vec )
    {
        stream << data << '\n';
    }

    return stream;
}

template<typename T, typename S>
std::ostream& operator<< ( std::ostream& stream, const std::map<T, S>& vec )
{
    for ( const std::pair<T, S>&  elem : vec )
    {
        stream << elem;
    }

    return stream;
}


template<typename T>
void print_map ( const T& vec )
{
    for ( const auto& elem : vec )
    {
        std::cout << elem.first << " " << elem.second << std::endl;
    }
}

