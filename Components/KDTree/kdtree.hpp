#ifndef KDTREE_HPP
#define KDTREE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include "../Vec2D/vec2d.hpp"

struct Neighbor
{
    Vec2D point;
    double distance;
    Neighbor(Vec2D p, double d) : point(p), distance(d) {}
    bool operator<(const Neighbor &other) const
    {
        return distance < other.distance;
    }
};

struct Node
{
    Vec2D data;
    int depth;
    Node *left;
    Node *right;
    Node(Vec2D data, int depth) : data(data), depth(depth), left(NULL), right(NULL) {}
};

class KDTree
{
private:
    Node *root;
    int k, size;

public:
    KDTree() : root(NULL), k(0) {}
    KDTree(int k) : root(NULL), k(k) {}
    ~KDTree() = default;
    void insert(Vec2D data);
    void print();
    bool search(Vec2D data);
    void clear();
    std::vector<Vec2D> GetAllPoints();
    std::vector<Vec2D> KNN(Vec2D data, int cantPoints);
    std::vector<Vec2D> ApproximateCentroids(std::vector<std::vector<Vec2D>> data);
    std::vector<Vec2D> Centroids(int k, std::vector<Vec2D> all_points);
    std::vector<std::vector<Vec2D>> KMeans(int k);
    std::vector<std::vector<Vec2D>> KMeans(std::vector<Vec2D> centroids, int count, std::vector<Vec2D> all_points);

private:
    void Insert(Node *&root, Vec2D data, int depth);
    void GetAllPointsRecursive(Node *node, std::vector<Vec2D> &allPoints);
    void Print(Node *root);
    bool Search(Node *root, Vec2D data, int depth);
    void KNNRecursive(Node *node, Vec2D query, int cantPoints, std::vector<Neighbor> &neighbors);
    double distance(Vec2D a, Vec2D b)
    {
        return std::sqrt(std::pow(a.getX() - b.getX(), 2) + std::pow(a.getY() - b.getY(), 2));
    }
};

#endif // KDTREE_HPP