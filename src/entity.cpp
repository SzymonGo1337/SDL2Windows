#include "entity.hpp"

Entity::Entity(float xPos, float yPos, SDL_Texture* txt) : x(xPos), y(yPos), texture(txt) {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

float Entity::getX() {
    return x;
}

float Entity::getY() {
    return y;
}

SDL_Texture* Entity::getTxt() {
    return texture;
}

SDL_Rect Entity::getCurrentFrame() {
    return currentFrame;
}