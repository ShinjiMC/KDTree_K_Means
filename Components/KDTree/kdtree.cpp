#include "KDTree.hpp"
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

void KDTree::insert(Vec2D data)
{
    Insert(root, data, 0);
}

void KDTree::Insert(Node *&root, Vec2D data, int depth)
{
    if (root == NULL)
    {
        root = new Node(data, depth);
        size++;
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

std::vector<Vec2D> KDTree::GetAllPoints()
{
    std::vector<Vec2D> allPoints;
    allPoints.reserve(size); // Reserva espacio para evitar reallocaciones frecuentes

    GetAllPointsRecursive(root, allPoints);

    return allPoints;
}

void KDTree::GetAllPointsRecursive(Node *node, std::vector<Vec2D> &allPoints)
{
    if (node == nullptr)
    {
        return;
    }

    GetAllPointsRecursive(node->left, allPoints);
    allPoints.push_back(node->data);
    GetAllPointsRecursive(node->right, allPoints);
}

std::vector<Vec2D> KDTree::ApproximateCentroids(std::vector<std::vector<Vec2D>> clusters)
{
    std::vector<Vec2D> newCentroids;
    newCentroids.reserve(clusters.size());

    for (int i = 0; i < clusters.size(); i++)
    {
        Vec2D centroid = Vec2D();
        for (const auto &point : clusters[i])
        {
            centroid = centroid + point;
            // std::cout << "el point" << point.getX() << "," << point.getY() << std::endl;
        }
        double size = clusters[i].size();
        // std::cout << "el centroid 1" << centroid.getX() << "," << centroid.getY() << std::endl;

        if (size != 0)
            centroid = centroid / size;
        // std::cout << "el centroid" << centroid.getX() << "," << centroid.getY() << std::endl;
        newCentroids.push_back(centroid);
    }
    return newCentroids;
}

std::vector<std::vector<Vec2D>> KDTree::KMeans(int k)
{
    std::vector<Vec2D> all_points = GetAllPoints();
    std::vector<Vec2D> centroids = Centroids(k, all_points);
    // for (int i = 0; i < all_points.size(); i++)
    //     std::cout << "Cluster " << i << ":" << all_points[i].getX() << "" << all_points[i].getY() << std::endl;
    return KMeans(centroids, 0, all_points);
}

std::vector<std::vector<Vec2D>> KDTree::KMeans(std::vector<Vec2D> centroids, int count, std::vector<Vec2D> points)
{

    KDTree centers(2);
    // std::cout << "Cluster " << std::endl;
    for (const auto &centroid : centroids)
    {
        centers.insert(centroid);
    }
    // std::cout << "Cluster 2" << std::endl;
    std::vector<std::vector<Vec2D>> clusters(centroids.size());
    for (int i = 0; i < size; i++)
    {
        // std::cout << "Cluster 3" << std::endl;

        std::vector<Vec2D> num = centers.KNN(points[i], 1);
        for (int j = 0; j < centroids.size(); j++)
        {
            if (num[0] == centroids[j])
            {
                clusters[j].push_back(points[i]);
                break;
            }
        }
    }
    // for (int i = 0; i < clusters.size(); i++)
    // std::cout << "Cluster " << i << ":" << clusters[i].size() << std::endl;
    std::vector<Vec2D> newCentroids = ApproximateCentroids(clusters);
    // for (int i = 0; i < newCentroids.size(); i++)
    //     std::cout << "nuevo centro " << i << ":" << newCentroids[i].getX() << "" << newCentroids[i].getY() << std::endl;
    if (count == 10 || newCentroids == centroids)
        return clusters;
    return KMeans(newCentroids, count + 1, points);
}