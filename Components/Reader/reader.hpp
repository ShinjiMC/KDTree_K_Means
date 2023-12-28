#ifndef READER_HPP
#define READER_HPP

#include "../KDTree/kdtree.hpp"
#include "../Direct/direct.hpp"
class Reader
{
public:
    KDTree readAndConvert(std::string fileN);
    Direct readAndConvertDirect(std::string fileN);
};

#endif // READER_HPP