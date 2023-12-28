#include <cmath>
#include "vec2d.hpp"

Vec2D::Vec2D(double xVal, double yVal) : x(xVal), y(yVal) {}

Vec2D::Vec2D() : x(0.0), y(0.0) {}

double Vec2D::getX() const { return x; }
double Vec2D::getY() const { return y; }
double Vec2D::getCord(int cord) const
{
    switch (cord)
    {
    case 0:
        return x;
    case 1:
        return y;
    default:
        return 0.0;
    }
}

double Vec2D::distance(const Vec2D &other) const
{
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

Vec2D Vec2D::operator+(const Vec2D &other) const
{
    return Vec2D(x + other.x, y + other.y);
}

Vec2D Vec2D::operator-(const Vec2D &other) const
{
    return Vec2D(x - other.x, y - other.y);
}

Vec2D Vec2D::operator*(double scalar) const
{
    return Vec2D(x * scalar, y * scalar);
}

Vec2D Vec2D::operator/(double scalar) const
{
    return Vec2D(x / scalar, y / scalar);
}

bool Vec2D::operator==(const Vec2D &other) const
{
    return x == other.x && y == other.y;
}

bool Vec2D::operator!=(const Vec2D &other) const
{
    return !(*this == other);
}

bool Vec2D::operator<(const Vec2D &other) const
{
    if (x != other.x)
        return x < other.x;
    return y < other.y;
}