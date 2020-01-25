//
// Created by ratanraj on 25/01/20.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *textureSheet, int x, int y) {
    objTexture = TextureManager::LoadTexture(textureSheet);
    xpos = x;
    ypos = y;
}

GameObject::GameObject() {

}

GameObject::~GameObject() {

}

void GameObject::Update() {
    switch(direction) {
        case DIR_LEFT:
            xpos--;
            srcRect.x = 0;
            srcRect.y = 32;
            break;
        case DIR_RIGHT:
            xpos++;
            srcRect.x = 32;
            srcRect.y = 32;
            break;
        case DIR_UP:
            ypos--;
            srcRect.x = 0;
            srcRect.y = 0;
            break;
        case DIR_DOWN:
            ypos++;
            srcRect.x = 32;
            srcRect.y = 0;
            break;
        default:
            break;
    }

    srcRect.h = 32;
    srcRect.w = 32;

    dstRect.x = xpos;
    dstRect.y = ypos;
    dstRect.w = srcRect.w;
    dstRect.h = srcRect.h;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &dstRect);
}

void GameObject::changeDirection(int dir) {
    direction = dir;
}
