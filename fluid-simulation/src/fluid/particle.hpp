#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle {
public:
    Particle(float x, float y);
    void update(float deltaTime);
    
    float getX() const;
    float getY() const;

private:
    float x; // Posição X da partícula
    float y; // Posição Y da partícula
    float vx; // Velocidade na direção X
    float vy; // Velocidade na direção Y
};

#endif // PARTICLE_HPP