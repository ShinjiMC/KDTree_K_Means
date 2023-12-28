#ifndef DIRECT_HPP
#define DIRECT_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "../Vec2D/vec2d.hpp"

class Direct
{
private:
    std::vector<Vec2D> points;

public:
    Direct() {}
    Direct(std::vector<Vec2D> points) : points(points) {}
    ~Direct() = default;
    void insert(Vec2D data) { points.push_back(data); }
    void print();
    bool search(Vec2D data);
    void clear() { points.clear(); }
    std::vector<Vec2D> KNN(Vec2D data, int cantPoints);
};
#endif // DIRECT_HPP