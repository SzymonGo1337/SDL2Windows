#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "entity.hpp"

class Window {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Window(const char* title, int width, int height);
    SDL_Texture* loadTexture(const char* filePath);
    void clean();
    void clear();
    void render(Entity& entity);
    void display();
};