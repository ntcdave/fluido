#include "fluid.hpp"
#include "particle.hpp"
#include <thread>
#include <vector>

Fluid::Fluid(int width, int height, int gridSize) 
    : width(width), height(height), gridSize(gridSize) {
    grid.resize(width/gridSize);
    for (auto& col : grid) {
        col.resize(height/gridSize);
    }
}

void Fluid::update() {
    updateGrid();
    
    // Divide o trabalho em threads
    const int threadCount = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    const int particlesPerThread = particles.size() / threadCount;
    
    for (int i = 0; i < threadCount; i++) {
        int startIdx = i * particlesPerThread;
        int endIdx = (i == threadCount - 1) ? particles.size() : (i + 1) * particlesPerThread;
        threads.emplace_back(&Fluid::updateParticlesParallel, this, startIdx, endIdx);
    }
    
    for (auto& thread : threads) {
        thread.join();
    }
}

void Fluid::updateGrid() {
    // Limpa o grid
    for (auto& col : grid) {
        for (auto& cell : col) {
            cell.particleIndices.clear();
        }
    }
    
    // Atualiza o grid com as posições das partículas
    for (size_t i = 0; i < particles.size(); i++) {
        const Particle& p = particles[i];
        int gridX = static_cast<int>(p.getX() / gridSize);
        int gridY = static_cast<int>(p.getY() / gridSize);
        
        if (gridX >= 0 && gridX < grid.size() && gridY >= 0 && gridY < grid[0].size()) {
            grid[gridX][gridY].particleIndices.push_back(i);
        }
    }
}

void Fluid::updateParticlesParallel(int startIdx, int endIdx) {
    for (int i = startIdx; i < endIdx; i++) {
        // Atualiza apenas partículas próximas usando o grid
        Particle& p = particles[i];
        int gridX = static_cast<int>(p.getX() / gridSize);
        int gridY = static_cast<int>(p.getY() / gridSize);
        
        // Verifica células vizinhas
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = gridX + dx;
                int ny = gridY + dy;
                
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
                    // Processa interações apenas com partículas próximas
                    // ...existing particle interaction code...
                }
            }
        }
        
        p.update(0.016f); // 60 FPS
    }
}

void Fluid::addParticle(float x, float y) {
    Particle newParticle(x, y);
    particles.push_back(newParticle);
}

const std::vector<Particle>& Fluid::getParticles() const {
    return particles;
}