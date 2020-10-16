#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.hpp"

Window::Window(const char* title, int width, int height) : window(NULL), renderer(NULL) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        std::cout << "Window Init Error | " << SDL_GetError() << "\n";
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

SDL_Texture* Window::loadTexture(const char* filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, filePath);
    if(texture == NULL) {
        std::cout << "Load Texture Error | " << SDL_GetError() << "\n";
        exit(EXIT_FAILURE);
    }

    return texture;
}

void Window::clean() {
    SDL_DestroyWindow(window);
}

void Window::clear() {
    SDL_RenderClear(renderer);
}

void Window::render(SDL_Texture* txt) {
    SDL_RenderCopy(renderer, txt, NULL, NULL);
}

void Window::display() {
    SDL_RenderPresent(renderer);
}