#include "particle.hpp"

Particle::Particle(float x, float y) : position(x, y), velocity(0, 0) {}

void Particle::update(float deltaTime) {
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

void Particle::setVelocity(float vx, float vy) {
    velocity.x = vx;
    velocity.y = vy;
}

Vector2D Particle::getPosition() const {
    return position;
}