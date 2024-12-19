#include "vector.hpp"
#include <cmath>

Vector::Vector(float x, float y) : x(x), y(y) {}

float Vector::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector Vector::normalize() const {
    float mag = magnitude();
    if (mag == 0) return Vector(0, 0);
    return Vector(x / mag, y / mag);
}

Vector Vector::operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(x - other.x, y - other.y);
}

Vector Vector::operator*(float scalar) const {
    return Vector(x * scalar, y * scalar);
}

Vector Vector::operator/(float scalar) const {
    if (scalar == 0) return Vector(0, 0);
    return Vector(x / scalar, y / scalar);
}