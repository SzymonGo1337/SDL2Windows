#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    bool isOpen;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL Init Error: " << SDL_GetError() << "\n";
        exit(EXIT_FAILURE);
    } else {
        window = SDL_CreateWindow("Simple", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
        if(window == NULL) {
            std::cout << "SDL Window Error: " << SDL_GetError() << "\n";
            exit(EXIT_FAILURE);
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            while(isOpen) {
                SDL_Event event;
                while(SDL_PollEvent(&event) > 0) {
                    switch (event.type) {
                        case SDL_QUIT:
                            isOpen = false;
                            break;
                    }

                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                    SDL_RenderClear(renderer);

                    SDL_Rect r;
                    r.x = 50;
                    r.y = 50;
                    r.w = 50;
                    r.h = 50;

                    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                    SDL_RenderFillRect(renderer, &r);
                    SDL_RenderPresent(renderer);

                }
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}