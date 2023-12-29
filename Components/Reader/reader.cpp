#include <iostream>
#include <fstream>
#include <sstream>
#include "reader.hpp"

KDTree Reader::readAndConvert(std::string fileN)
{
    std::string filename = "../Resources/";
    filename += fileN;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file " << filename << std::endl;
        throw std::runtime_error("Unable to open file " + filename);
    }
    std::string firstLine;
    std::getline(file, firstLine);
    KDTree kdtree(2);
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string token;
        double x, y;
        if (std::getline(ss, token, ','))
            x = std::stoi(token);
        if (std::getline(ss, token, '\n'))
            y = std::stoi(token);
        kdtree.insert(Vec2D(x, y));
    }
    file.close();
    return kdtree;
}

Direct Reader::readAndConvertDirect(std::string fileN)
{
    std::string filename = "../Resources/";
    filename += fileN;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file " << filename << std::endl;
        throw std::runtime_error("Unable to open file " + filename);
    }
    std::string firstLine;
    std::getline(file, firstLine);
    Direct direct;
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string token;
        double x, y;
        if (std::getline(ss, token, ','))
            x = std::stoi(token);
        if (std::getline(ss, token, '\n'))
            y = std::stoi(token);
        direct.insert(Vec2D(x, y));
    }
    file.close();
    return direct;
}