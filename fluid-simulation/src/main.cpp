#include <SDL2/SDL.h>
#include "fluid/fluid.hpp"
#include "renderer/renderer.hpp"

const int WIDTH = 800;
const int HEIGHT = 600;

int main(int argc, char* argv[]) {
    // Inicializa a SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1;
    }

    // Cria a janela
    SDL_Window* window = SDL_CreateWindow("Simulação de Fluído", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!window) {
        SDL_Quit();
        return -1;
    }

    // Cria o contexto de renderização
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    Fluid fluid;
    Renderer fluidRenderer(renderer);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            // Gerencia eventos de movimento do mouse
            if (event.type == SDL_MOUSEMOTION) {
                int mouseX = event.motion.x;
                int mouseY = event.motion.y;
                fluid.addParticle(mouseX, mouseY);
            }
        }

        // Atualiza a simulação
        fluid.update();

        // Renderiza o fluído
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        fluidRenderer.renderFluid(fluid);
        fluidRenderer.renderParticles(fluid);
        SDL_RenderPresent(renderer);
    }

    // Limpeza
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}