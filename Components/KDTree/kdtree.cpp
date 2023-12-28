#include "KDTree.hpp"
#include <limits>

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