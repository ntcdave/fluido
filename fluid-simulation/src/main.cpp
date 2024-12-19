#include <SDL2/SDL.h>
#include "fluid/fluid.hpp"
#include "renderer/renderer.hpp"

int main(int argc, char* argv[]) {
    const int WIDTH = 800;
    const int HEIGHT = 600;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1;
    }

    Renderer renderer(WIDTH, HEIGHT);
    Fluid fluid(WIDTH, HEIGHT);
    
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_MOUSEMOTION) {
                int mouseX = event.motion.x;
                int mouseY = event.motion.y;
                fluid.addParticle(mouseX, mouseY);
            }
        }

        fluid.update();
        
        renderer.clear();
        renderer.renderParticles(fluid.getParticles());
        renderer.present();
    }

    SDL_Quit();
    return 0;
}