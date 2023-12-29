#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../KDTree/kdtree.hpp"
#include "../Reader/reader.hpp"
#include "../Direct/direct.hpp"

class KDTreeTest : public ::testing::Test
{
protected:
    KDTree kdtree;
    Reader csv;

    void SetUp() override
    {
        kdtree = KDTree(2);
    }

    void TearDown() override
    {
        kdtree.clear();
    }
};

class DirectTest : public ::testing::Test
{
protected:
    Direct direct;
    Reader csv;

    void SetUp() override
    {
        direct = Direct();
    }

    void TearDown() override
    {
        direct.clear();
    }
};

void testPointsKDTree(const std::string &filename, KDTree &kdtree)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }
    std::string firstLine;
    std::getline(file, firstLine);
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string token;
        long double x, y;

        if (std::getline(ss, token, ','))
            x = std::stold(token);
        if (std::getline(ss, token, '\n'))
            y = std::stold(token);

        EXPECT_TRUE(kdtree.search(Vec2D(x, y))) << "Point (" << x << ", " << y << ") not found in the KDTree.";
    }
    file.close();
}

void testPointsDirect(const std::string &filename, Direct &direct)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }
    std::string firstLine;
    std::getline(file, firstLine);
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string token;
        long double x, y;

        if (std::getline(ss, token, ','))
            x = std::stold(token);
        if (std::getline(ss, token, '\n'))
            y = std::stold(token);

        EXPECT_TRUE(direct.search(Vec2D(x, y))) << "Point (" << x << ", " << y << ") not found in the KDTree.";
    }
    file.close();
}

// KDTree Test
TEST_F(KDTreeTest, InsertionPointsFromCSVTest_1)
{
    try
    {
        kdtree = csv.readAndConvert("data2k.csv");
    }
    catch (const std::runtime_error &e)
    {
        FAIL() << "Error al leer e insertar puntos desde el archivo CSV: " << e.what();
    }
}

TEST_F(KDTreeTest, Insertion_Search_PointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert("data2k.csv");
    std::string filename = "../Resources/data2k.csv";
    testPointsKDTree(filename, kdtree);
}

TEST_F(KDTreeTest, KMEANS_5_FromCSVTest_1000)
{
    kdtree = csv.readAndConvert("data2k.csv", 1000);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_15_FromCSVTest_1000)
{
    kdtree = csv.readAndConvert("data2k.csv", 1000);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_25_FromCSVTest_1000)
{
    kdtree = csv.readAndConvert("data2k.csv", 1000);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_50_FromCSVTest_1000)
{
    kdtree = csv.readAndConvert("data2k.csv", 1000);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_75_FromCSVTest_1000)
{
    kdtree = csv.readAndConvert("data2k.csv", 1000);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_5_FromCSVTest_1150)
{
    kdtree = csv.readAndConvert("data2k.csv", 1150);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_15_FromCSVTest_1150)
{
    kdtree = csv.readAndConvert("data2k.csv", 1150);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_25_FromCSVTest_1150)
{
    kdtree = csv.readAndConvert("data2k.csv", 1150);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_50_FromCSVTest_1150)
{
    kdtree = csv.readAndConvert("data2k.csv", 1150);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_75_FromCSVTest_1150)
{
    kdtree = csv.readAndConvert("data2k.csv", 1150);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_5_FromCSVTest_1300)
{
    kdtree = csv.readAndConvert("data2k.csv", 1300);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_15_FromCSVTest_1300)
{
    kdtree = csv.readAndConvert("data2k.csv", 1300);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_25_FromCSVTest_1300)
{
    kdtree = csv.readAndConvert("data2k.csv", 1300);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_50_FromCSVTest_1300)
{
    kdtree = csv.readAndConvert("data2k.csv", 1300);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_75_FromCSVTest_1300)
{
    kdtree = csv.readAndConvert("data2k.csv", 1300);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_5_FromCSVTest_1450)
{
    kdtree = csv.readAndConvert("data2k.csv", 1450);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_15_FromCSVTest_1450)
{
    kdtree = csv.readAndConvert("data2k.csv", 1450);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_25_FromCSVTest_1450)
{
    kdtree = csv.readAndConvert("data2k.csv", 1450);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_50_FromCSVTest_1450)
{
    kdtree = csv.readAndConvert("data2k.csv", 1450);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_75_FromCSVTest_1450)
{
    kdtree = csv.readAndConvert("data2k.csv", 1450);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_5_FromCSVTest_1600)
{
    kdtree = csv.readAndConvert("data2k.csv", 1600);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_15_FromCSVTest_1600)
{
    kdtree = csv.readAndConvert("data2k.csv", 1600);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_25_FromCSVTest_1600)
{
    kdtree = csv.readAndConvert("data2k.csv", 1600);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_50_FromCSVTest_1600)
{
    kdtree = csv.readAndConvert("data2k.csv", 1600);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_75_FromCSVTest_1600)
{
    kdtree = csv.readAndConvert("data2k.csv", 1600);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_5_FromCSVTest_1750)
{
    kdtree = csv.readAndConvert("data2k.csv", 1750);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_15_FromCSVTest_1750)
{
    kdtree = csv.readAndConvert("data2k.csv", 1750);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_25_FromCSVTest_1750)
{
    kdtree = csv.readAndConvert("data2k.csv", 1750);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_50_FromCSVTest_1750)
{
    kdtree = csv.readAndConvert("data2k.csv", 1750);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_75_FromCSVTest_1750)
{
    kdtree = csv.readAndConvert("data2k.csv", 1750);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_5_FromCSVTest_1900)
{
    kdtree = csv.readAndConvert("data2k.csv", 1900);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_15_FromCSVTest_1900)
{
    kdtree = csv.readAndConvert("data2k.csv", 1900);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_25_FromCSVTest_1900)
{
    kdtree = csv.readAndConvert("data2k.csv", 1900);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_50_FromCSVTest_1900)
{
    kdtree = csv.readAndConvert("data2k.csv", 1900);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_75_FromCSVTest_1900)
{
    kdtree = csv.readAndConvert("data2k.csv", 1900);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_5_FromCSVTest_2050)
{
    kdtree = csv.readAndConvert("data2k.csv", 2050);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_15_FromCSVTest_2050)
{
    kdtree = csv.readAndConvert("data2k.csv", 2050);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_25_FromCSVTest_2050)
{
    kdtree = csv.readAndConvert("data2k.csv", 2050);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_50_FromCSVTest_2050)
{
    kdtree = csv.readAndConvert("data2k.csv", 2050);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_75_FromCSVTest_2050)
{
    kdtree = csv.readAndConvert("data2k.csv", 2050);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_5_FromCSVTest_2200)
{
    kdtree = csv.readAndConvert("data2k.csv", 2200);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_15_FromCSVTest_2200)
{
    kdtree = csv.readAndConvert("data2k.csv", 2200);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_25_FromCSVTest_2200)
{
    kdtree = csv.readAndConvert("data2k.csv", 2200);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_50_FromCSVTest_2200)
{
    kdtree = csv.readAndConvert("data2k.csv", 2200);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_75_FromCSVTest_2200)
{
    kdtree = csv.readAndConvert("data2k.csv", 2200);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_5_FromCSVTest_2400)
{
    kdtree = csv.readAndConvert("data2k.csv", 2400);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_15_FromCSVTest_2400)
{
    kdtree = csv.readAndConvert("data2k.csv", 2400);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_25_FromCSVTest_2400)
{
    kdtree = csv.readAndConvert("data2k.csv", 2400);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_50_FromCSVTest_2400)
{
    kdtree = csv.readAndConvert("data2k.csv", 2400);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(KDTreeTest, KMEANS_75_FromCSVTest_2400)
{
    kdtree = csv.readAndConvert("data2k.csv", 2400);
    std::vector<std::vector<Vec2D>> clusters = kdtree.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

// Direct Test
TEST_F(DirectTest, InsertionPointsFromCSVTest_1)
{
    try
    {
        direct = csv.readAndConvertDirect("data2k.csv");
    }
    catch (const std::runtime_error &e)
    {
        FAIL() << "Error al leer e insertar puntos desde el archivo CSV: " << e.what();
    }
}

TEST_F(DirectTest, Insertion_Search_PointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect("data2k.csv");
    std::string filename = "../Resources/data2k.csv";
    testPointsDirect(filename, direct);
}

TEST_F(DirectTest, KMEANS_5_FromCSVTest_1000)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1000);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_15_FromCSVTest_1000)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1000);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_25_FromCSVTest_1000)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1000);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_50_FromCSVTest_1000)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1000);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_75_FromCSVTest_1000)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1000);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_5_FromCSVTest_1150)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1150);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_15_FromCSVTest_1150)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1150);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_25_FromCSVTest_1150)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1150);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_50_FromCSVTest_1150)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1150);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_75_FromCSVTest_1150)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1150);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_5_FromCSVTest_1300)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1300);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_15_FromCSVTest_1300)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1300);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_25_FromCSVTest_1300)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1300);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_50_FromCSVTest_1300)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1300);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_75_FromCSVTest_1300)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1300);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_5_FromCSVTest_1450)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1450);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_15_FromCSVTest_1450)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1450);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_25_FromCSVTest_1450)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1450);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_50_FromCSVTest_1450)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1450);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_75_FromCSVTest_1450)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1450);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_5_FromCSVTest_1600)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1600);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_15_FromCSVTest_1600)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1600);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_25_FromCSVTest_1600)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1600);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_50_FromCSVTest_1600)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1600);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_75_FromCSVTest_1600)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1600);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_5_FromCSVTest_1750)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1750);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_15_FromCSVTest_1750)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1750);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_25_FromCSVTest_1750)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1750);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_50_FromCSVTest_1750)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1750);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_75_FromCSVTest_1750)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1750);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_5_FromCSVTest_1900)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1900);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_15_FromCSVTest_1900)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1900);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_25_FromCSVTest_1900)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1900);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_50_FromCSVTest_1900)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1900);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_75_FromCSVTest_1900)
{
    direct = csv.readAndConvertDirect("data2k.csv", 1900);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_5_FromCSVTest_2050)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2050);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_15_FromCSVTest_2050)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2050);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_25_FromCSVTest_2050)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2050);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_50_FromCSVTest_2050)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2050);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_75_FromCSVTest_2050)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2050);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_5_FromCSVTest_2200)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2200);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_15_FromCSVTest_2200)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2200);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_25_FromCSVTest_2200)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2200);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_50_FromCSVTest_2200)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2200);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_75_FromCSVTest_2200)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2200);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_5_FromCSVTest_2400)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2400);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(5);
    EXPECT_EQ(clusters.size(), 5) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_15_FromCSVTest_2400)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2400);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(15);
    EXPECT_EQ(clusters.size(), 15) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_25_FromCSVTest_2400)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2400);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(25);
    EXPECT_EQ(clusters.size(), 25) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_50_FromCSVTest_2400)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2400);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(50);
    EXPECT_EQ(clusters.size(), 50) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}

TEST_F(DirectTest, KMEANS_75_FromCSVTest_2400)
{
    direct = csv.readAndConvertDirect("data2k.csv", 2400);
    std::vector<std::vector<Vec2D>> clusters = direct.KMeans(75);
    EXPECT_EQ(clusters.size(), 75) << "The number of clusters is not the expected.";
    for (const auto &cluster : clusters)
        EXPECT_NE(cluster.size(), 0) << "The size of a cluster is 0.";
}