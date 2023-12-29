#ifndef VEC2D_HPP
#define VEC2D_HPP
#include <iostream>
class Vec2D
{
public:
    Vec2D(long double xVal, long double yVal);
    Vec2D();
    ~Vec2D() = default;

    double getX() const;
    double getY() const;
    double getCord(int cord) const;
    double distance(const Vec2D &other) const;
    Vec2D operator+(const Vec2D &other) const;
    Vec2D operator-(const Vec2D &other) const;
    Vec2D operator*(double scalar) const;
    Vec2D operator/(double scalar) const;
    bool operator==(const Vec2D &other) const;
    bool operator!=(const Vec2D &other) const;
    bool operator<(const Vec2D &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Vec2D &vec);

private:
    long double x, y;
};

#endif // VEC2D_HPP