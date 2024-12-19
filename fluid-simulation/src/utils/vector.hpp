#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

class Vector2 {
public:
    float x;
    float y;

    Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    float length() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2 normalized() const {
        float len = length();
        return len > 0 ? Vector2(x / len, y / len) : Vector2(0, 0);
    }

    float magnitude() const {
        return std::sqrt(x * x + y * y);
    }
};

#endif // VECTOR_HPP