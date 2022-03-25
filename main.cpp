#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

template<typename T>
void print_vector( const T &vec)
{
    for ( auto const& elem :vec)
    {
        std::cout << elem << std::endl;
    }
};

int main() {
  std::string line;
  std::ifstream myfile ("kanas/hiragana/tab.txt");

//   std::vector<std::string> vec;
  if (myfile.is_open())
  {
    while ( std::getline (myfile,line) )
    {
        print_vector(split(line, ' '));
    }
    myfile.close();
  }
  else
  {
    std::cerr << "Unable to open file" << '\n';
    return 0;
  }
  return 0;
}
