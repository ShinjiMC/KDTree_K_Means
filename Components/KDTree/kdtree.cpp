#include "kdtree.hpp"
#include <limits>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <iomanip>
#include <random>
#include <algorithm>
#include <stdexcept>
#include <set>
#include <ctime>
#include <random>
#include <thread>
#include <chrono>

void KDTree::insert(Vec2D data)
{
    Insert(root, data, 0);
}

void KDTree::Insert(Node *&root, Vec2D data, int depth)
{
    if (root == NULL)
    {
        root = new Node(data, depth);
        return;
    }
    int cd = depth % k;
    if (cd == 0)
    {
        if (data.getX() < root->data.getX())
            Insert(root->left, data, ++depth);
        else
            Insert(root->right, data, ++depth);
    }
    else
    {
        if (data.getY() < root->data.getY())
            Insert(root->left, data, ++depth);
        else
            Insert(root->right, data, ++depth);
    }
}

void KDTree::print()
{
    Print(root);
}

void KDTree::Print(Node *root)
{
    if (root == NULL)
        return;
    Print(root->left);
    std::cout << "(" << root->data.getX() << ", " << root->data.getY();
    std::cout << ") Level:" << root->depth << std::endl;
    Print(root->right);
}

bool KDTree::search(Vec2D data)
{
    return Search(root, data, 0);
}

bool KDTree::Search(Node *root, Vec2D data, int depth)
{
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    int cd = depth % k;
    if (cd == 0)
    {
        if (data.getX() < root->data.getX())
            return Search(root->left, data, ++depth);
        else
            return Search(root->right, data, ++depth);
    }
    else
    {
        if (data.getY() < root->data.getY())
            return Search(root->left, data, ++depth);
        else
            return Search(root->right, data, ++depth);
    }
}

void KDTree::clear()
{
    delete root;
    root = NULL;
}

std::vector<Vec2D> KDTree::KNN(Vec2D data, int cantPoints)
{
    std::vector<Neighbor> queue;
    KNNRecursive(root, data, cantPoints, queue);
    std::vector<Vec2D> neighbours;
    for (auto &n : queue)
        neighbours.push_back(n.point);
    return neighbours;
}

void KDTree::KNNRecursive(Node *node, Vec2D query, int cantPoints, std::vector<Neighbor> &neighbors)
{
    if (node == nullptr)
        return;

    double dist = distance(node->data, query);
    if (neighbors.size() < cantPoints)
    {
        neighbors.emplace_back(node->data, dist);
        std::push_heap(neighbors.begin(), neighbors.end());
    }
    else if (dist < neighbors.front().distance)
    {
        std::pop_heap(neighbors.begin(), neighbors.end());
        neighbors.back() = Neighbor(node->data, dist);
        std::push_heap(neighbors.begin(), neighbors.end());
    }

    int axis = node->depth % k;
    Node *firstNode = nullptr;
    Node *secondNode = nullptr;

    if (query.getCord(axis) < node->data.getCord(axis))
    {
        firstNode = node->left;
        secondNode = node->right;
    }
    else
    {
        firstNode = node->right;
        secondNode = node->left;
    }

    KNNRecursive(firstNode, query, cantPoints, neighbors);
    if (neighbors.size() < cantPoints || std::fabs(query.getCord(axis) - node->data.getCord(axis)) < neighbors.front().distance)
    {
        KNNRecursive(secondNode, query, cantPoints, neighbors);
    }
}

std::vector<Vec2D> KDTree::Centroids(int k, std::vector<Vec2D> points)
{
    std::vector<Vec2D> centroids;
    std::mt19937 gen(static_cast<long unsigned int>(123));
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

std::vector<Vec2D> KDTree::GetAllPoints()
{
    std::vector<Vec2D> allPoints;
    GetAllPointsRecursive(root, allPoints);
    return allPoints;
}

void KDTree::GetAllPointsRecursive(Node *node, std::vector<Vec2D> &allPoints)
{
    if (node == nullptr)
        return;
    GetAllPointsRecursive(node->left, allPoints);
    allPoints.push_back(node->data);
    GetAllPointsRecursive(node->right, allPoints);
}

std::vector<Vec2D> KDTree::ApproximateCentroids(std::vector<std::vector<Vec2D>> clusters)
{
    std::vector<Vec2D> newCentroids;
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

std::vector<std::vector<Vec2D>> KDTree::KMeans(int k)
{
    std::vector<Vec2D> all_points = GetAllPoints();
    std::vector<Vec2D> centroids = Centroids(k, all_points);
    return KMeans(centroids, 0, all_points);
}

std::vector<std::vector<Vec2D>> KDTree::KMeans(std::vector<Vec2D> centroids, int count, std::vector<Vec2D> points)
{

    KDTree centers(2);
    for (const auto &centroid : centroids)
        centers.insert(centroid);
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
    return KMeans(newCentroids, count + 1, points);
}

void KDTree::ShowKMeans(int k)
{
    std::vector<Vec2D> all_points = GetAllPoints();
    std::vector<Vec2D> centroids = Centroids(k, all_points);
    Vtk_Builder vtk;
    ShowKMeans(vtk, centroids, 0, all_points);
}

void KDTree::ShowKMeans(Vtk_Builder &vtk, std::vector<Vec2D> centroids, int count, std::vector<Vec2D> points)
{
    KDTree centers(2);
    for (const auto &centroid : centroids)
        centers.insert(centroid);
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
    vtk.clear();
    vtk.addClusters(clusters);
    vtk.show();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::vector<Vec2D> newCentroids = ApproximateCentroids(clusters);
    if (count < 10 && newCentroids != centroids)
        ShowKMeans(vtk, newCentroids, count + 1, points);
}