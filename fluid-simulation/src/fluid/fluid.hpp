#ifndef FLUID_HPP
#define FLUID_HPP

#include <vector>
#include "particle.hpp"

class Fluid {
public:
    Fluid(int width, int height, int gridSize = 50);
    void update();
    void addParticle(const Particle& particle);
    
private:
    struct Cell {
        std::vector<size_t> particleIndices;
    };

    int width;
    int height;
    int gridSize;
    std::vector<Particle> particles;
    std::vector<std::vector<Cell>> grid;
    
    void updateGrid();
    void updateParticlesParallel(int startIdx, int endIdx);
};

#endif // FLUID_HPP