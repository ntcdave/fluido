#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "../utils/vector.hpp"

class Particle {
public:
    Particle(float x, float y);
    void update(float deltaTime);
    float getX() const { return position.x; }
    float getY() const { return position.y; }
    
private:
    Vector2 position;
    Vector2 velocity;
};

#endif // PARTICLE_HPP