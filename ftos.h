#ifndef FTOS_H
#define FTOS_H

#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>

auto ftos(const std::string& file_name) -> std::string
{
    std::ifstream ifs(file_name);
    std::stringstream buffer;
    buffer << ifs.rdbuf();

    return buffer.str();
}

#endif // FTOS_H
