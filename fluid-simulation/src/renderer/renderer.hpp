#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include <vector>
#include "fluid.hpp"
#include "particle.hpp"

class Renderer {
public:
    Renderer(int width, int height);
    ~Renderer();

    void renderFluid(const Fluid& fluid);
    void renderParticles(const std::vector<Particle>& particles);
    void clear();
    void present();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
};

#endif // RENDERER_HPP