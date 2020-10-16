#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "window.hpp"
#include "entity.hpp"

int main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL2 Init Error | " << SDL_GetError() << "\n";
        exit(EXIT_FAILURE);
    }

    if(!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "SDL2 Image Init Error | " << SDL_GetError() << "\n";
        exit(EXIT_FAILURE);
    }

    Window window("Simple", 1280, 720);

    SDL_Texture* grass = window.loadTexture("grass.png");

    Entity platform0(100, 100, grass);

    bool isOpen = true;

    SDL_Event event;

    while(isOpen) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                isOpen = false;
            }
        }

        window.clear();

        window.render(platform0);

        window.display();
    }

    window.clean();
    SDL_Quit();

    return 0;
}