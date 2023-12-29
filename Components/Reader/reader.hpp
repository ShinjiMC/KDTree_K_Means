#ifndef READER_HPP
#define READER_HPP

#include "../KDTree/kdtree.hpp"
#include "../Direct/direct.hpp"
class Reader
{
public:
    KDTree readAndConvert(std::string fileN);
    KDTree readAndConvert(std::string fileN, int cantPoints);
    Direct readAndConvertDirect(std::string fileN);
    Direct readAndConvertDirect(std::string fileN, int cantPoints);
};

#endif // READER_HPP