#ifndef KMEANS_HPP
#define KMEANS_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include "../Vec2D/vec2d.hpp"

class KMeans
{
public:
    void printVector(Vec2D data);
    std::vector<Vec2D> getThreeRandomPoints(std::vector<Vec2D> data, int quantity);
    std::vector<Vec2D> Centroids(std::vector<std::vector<Vec2D>> centroide);
};

#endif // KDTREE_HPP