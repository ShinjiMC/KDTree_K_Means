#include "direct.hpp"
#include <set>
#include <ctime>
#include <random>

struct ComparePairs
{
    bool operator()(const std::pair<long double, Vec2D> &a, const std::pair<long double, Vec2D> &b) const
    {
        return a.first < b.first;
    }
};

void Direct::print()
{
    for (const auto &c : points)
        std::cout << "(" << c.getX() << ", " << c.getY() << ")" << std::endl;
}

bool Direct::search(Vec2D data)
{
    for (const auto &c : points)
        if (c == data)
            return true;
    return false;
}

std::vector<Vec2D> Direct::KNN(Vec2D data, int cantPoints)
{
    std::set<std::pair<double, Vec2D>, ComparePairs> closestPoints;
    for (const auto &c : this->points)
    {
        double dist = c.distance(data); // Cálculo euclidiano
        if (closestPoints.size() < static_cast<size_t>(cantPoints))
            closestPoints.emplace(dist, c);
        else
        {
            if (dist < closestPoints.rbegin()->first)
            {
                closestPoints.erase(std::prev(closestPoints.end()));
                closestPoints.emplace(dist, c);
            }
        }
    }

    std::vector<Vec2D> neighbours;
    neighbours.reserve(cantPoints);
    for (const auto &pair : closestPoints)
        neighbours.push_back(pair.second);
    return neighbours;
}

std::vector<Vec2D> Direct::Centroids(int k)
{
    std::vector<Vec2D> centroids;
    centroids.reserve(k);
    std::mt19937 gen(static_cast<long unsigned int>(12));
    std::uniform_int_distribution<int> distribution(0, points.size() - 1);
    for (int i = 0; i < k; i++)
    {
        int ind = distribution(gen);
        while (std::find(centroids.begin(), centroids.end(), points[ind]) != centroids.end())
            ind = distribution(gen);
        centroids.push_back(points[ind]);
    }
    return centroids;
}

std::vector<Vec2D> Direct::ApproximateCentroids(std::vector<std::vector<Vec2D>> clusters)
{
    std::vector<Vec2D> newCentroids;
    newCentroids.reserve(clusters.size());
    for (int i = 0; i < clusters.size(); i++)
    {
        Vec2D centroid = Vec2D();
        for (const auto &point : clusters[i])
            centroid = centroid + point;
        double size = clusters[i].size();
        if (size != 0)
            centroid = centroid / size;
        newCentroids.push_back(centroid);
    }
    return newCentroids;
}

std::vector<std::vector<Vec2D>> Direct::KMeans(int k)
{
    std::vector<Vec2D> centroids = Centroids(k);
    return KMeans(centroids, 0);
}

std::vector<std::vector<Vec2D>> Direct::KMeans(std::vector<Vec2D> centroids, int count)
{

    Direct centers = Direct(centroids);
    std::vector<std::vector<Vec2D>> clusters(centroids.size());
    for (int i = 0; i < points.size(); i++)
    {
        std::vector<Vec2D> num = centers.KNN(points[i], 1);
        for (int j = 0; j < centroids.size(); j++)
            if (num[0] == centroids[j])
            {
                clusters[j].push_back(points[i]);
                break;
            }
    }
    std::vector<Vec2D> newCentroids = ApproximateCentroids(clusters);
    if (count == 10 || newCentroids == centroids)
        return clusters;
    return KMeans(newCentroids, count + 1);
}