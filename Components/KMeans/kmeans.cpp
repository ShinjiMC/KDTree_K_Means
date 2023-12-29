#include "KMeans.hpp"
#include "KDTree\kdtree.hpp"
#include "KDTree\kdtree.cpp"

#include <limits>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <iomanip>
#include <random>
#include <algorithm>

void KMeans::printVector(Vec2D data)
{
}

std::vector<Vec2D> KMeans::getThreeRandomPoints(const std::vector<Vec2D> puntos, int quantity)
{
    std::vector<Vec2D> all_centroides;
    if (puntos.size() < quantity || quantity < 1)
        return all_centroides;

    std::mt19937 gen(static_cast<long unsigned int>(12));
    std::uniform_int_distribution<int> distribution(0, puntos.size() - 1);

    for (int i = 0; i < quantity; ++i)
    {
        int indice = distribution(gen);
        while (!centroides_set.insert(puntos[indice]).second)
            indice = distribution(gen);

        all_centroides.push_back(puntos[indice]);
    }

    return all_centroides;
}

std::vector<Vec2D> KMeans::newCentroides(std::vector<std::vector<Vec2D>> clusteres)
{
    std::vector<Vec2D> newCentroides;
    for (int i = 0; i < clusteres.size(); i++)
    {
        Vec2D newCentroide = {0, 0};
        for (const auto &point : clusteres[i])
            newCentroide = newCentroide + point;
        int size = clusteres[i].size();
        if (size != 0)
            newCentroide = newCentroide / size;
        newCentroides.push_back(newCentroide);
    }
    return newCentroides;
}

std::vector<std::vector<Vec2D>>
KMeans_def(const std::vector<Vec2D> &all_centroides, std::vector<Vec2D> &all_points)
{
    kdt::KDTree<3> kdtree_centroides;
    for (auto &row : all_centroides)
        kdtree_centroides.insert(row);
    vector<vector<Point3D>> clusters(all_centroides.size());
    for (int i = 0; i < all_points.size(); i++)
    {
        vector<Point3D> num = kdtree_centroides.searchKNN(all_points[i], 1);
        for (int j = 0; j < all_centroides.size(); ++j)
        {
            if (num[0] == all_centroides[j])
            {
                clusters[j].push_back(all_points[i]);
                break;
            }
        }
    }
    // for (int i = 0; i < clusters.size(); ++i)
    //     std::cout << "cluster " << i + 1 << " => " << clusters[i].size() << std::endl;
    vector<Point3D> newCentroides = newCenters(clusters);
    // printVector(newCentroides);
    double distanceThreshold = 8.4;
    double distance = 0.0;
    for (int i = 0; i < all_centroides.size(); ++i)
        distance += EuclideanDistance(all_centroides[i], newCentroides[i]);
    if (distance < distanceThreshold)
    {
        // std::cout << "Algoritmo convergió. Distancia: " << distance << std::endl;
        return clusters;
    }
    // std::cout << "Algoritmo no convergió. Distancia: " << distance << std::endl;
    return KMeans_def(newCentroides, all_points);
}