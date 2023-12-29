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
        double x, y;

        if (std::getline(ss, token, ','))
            x = std::stod(token);
        if (std::getline(ss, token, '\n'))
            y = std::stod(token);

        EXPECT_TRUE(kdtree.search(Vec2D(x, y))) << "Point (" << x << ", " << y << ") not found in the KDTree.";
    }
    file.close();
}

void testPointsKNN_KDTREE(const std::string &filename, KDTree &kdtree, int cantPoints)
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
        double x, y;

        if (std::getline(ss, token, ','))
            x = std::stod(token);
        if (std::getline(ss, token, '\n'))
            y = std::stod(token);
        EXPECT_NO_THROW({ kdtree.KNN(Vec2D(x, y), cantPoints); }) << "Error occurred while executing KNN for point (" << x << ", " << y << ").";
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
        double x, y;

        if (std::getline(ss, token, ','))
            x = std::stod(token);
        if (std::getline(ss, token, '\n'))
            y = std::stod(token);

        EXPECT_TRUE(direct.search(Vec2D(x, y))) << "Point (" << x << ", " << y << ") not found in the KDTree.";
    }
    file.close();
}

void testPointsKNN_Direct(const std::string &filename, Direct &direct, int cantPoints)
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
        double x, y;

        if (std::getline(ss, token, ','))
            x = std::stod(token);
        if (std::getline(ss, token, '\n'))
            y = std::stod(token);
        EXPECT_NO_THROW({ direct.KNN(Vec2D(x, y), cantPoints); }) << "Error occurred while executing KNN for point (" << x << ", " << y << ").";
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

// KDTree Test
TEST_F(KDTreeTest, Insertion_Search_PointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert("data2k.csv");
    std::string filename = "../Resources/data2k.csv";
    testPointsKDTree(filename, kdtree);
}

// Direct Test
TEST_F(DirectTest, Insertion_Search_PointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect("data2k.csv");
    std::string filename = "../Resources/data2k.csv";
    testPointsDirect(filename, direct);
}

// KDTree Test
TEST_F(KDTreeTest, Insertion_KNN_1_PointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert("data2k.csv");
    std::string filename = "../Resources/data2k.csv";
    testPointsKNN_KDTREE(filename, kdtree, 1);
}

TEST_F(KDTreeTest, Insertion_KNN_MID_PointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert("data2k.csv");
    std::string filename = "../Resources/data2k.csv";
    testPointsKNN_KDTREE(filename, kdtree, 1200);
}

TEST_F(KDTreeTest, Insertion_KNN_MAX_PointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert("data2k.csv");
    std::string filename = "../Resources/data2k.csv";
    testPointsKNN_KDTREE(filename, kdtree, 2400);
}

// Direct Test
TEST_F(DirectTest, Insertion_KNN_1_PointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect("data2k.csv");
    std::string filename = "../Resources/data2k.csv";
    testPointsKNN_Direct(filename, direct, 1);
}

TEST_F(DirectTest, Insertion_KNN_MID_PointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect("data2k.csv");
    std::string filename = "../Resources/data2k.csv";
    testPointsKNN_Direct(filename, direct, 1200);
}

TEST_F(DirectTest, Insertion_KNN_MAX_PointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect("data2k.csv");
    std::string filename = "../Resources/data2k.csv";
    testPointsKNN_Direct(filename, direct, 2400);
}