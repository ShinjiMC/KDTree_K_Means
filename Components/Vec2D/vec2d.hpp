#ifndef VEC2D_HPP
#define VEC2D_HPP

class Vec2D
{
public:
    Vec2D(double xVal, double yVal);
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

private:
    double x, y;
};
#endif // VEC2D_HPP