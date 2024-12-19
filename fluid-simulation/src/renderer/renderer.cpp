#include "renderer.hpp"

Renderer::Renderer(int width, int height) : width(width), height(height) {
    window = SDL_CreateWindow("Fluid Simulation", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        width, height, SDL_WINDOW_SHOWN);
    
    renderer = SDL_CreateRenderer(window, -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Renderer::renderParticles(const std::vector<Particle>& particles) {
    SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
    for (const auto& particle : particles) {
        SDL_Rect rect = {
            static_cast<int>(particle.getX()) - 2,
            static_cast<int>(particle.getY()) - 2,
            4, 4
        };
        SDL_RenderFillRect(renderer, &rect);
    }
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}