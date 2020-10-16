#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Entity {
private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;

public:
    Entity(float xPos, float yPos, SDL_Texture* txt);
    float getX();
    float getY();
    SDL_Texture* getTxt();
    SDL_Rect getCurrentFrame();

};