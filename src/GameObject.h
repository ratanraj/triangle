//
// Created by ratanraj on 25/01/20.
//

#ifndef TRIANGLE_GAMEOBJECT_H
#define TRIANGLE_GAMEOBJECT_H


#include <SDL_render.h>

class GameObject {
public:
    GameObject(const char *textureSheet);
    GameObject();
    ~GameObject();
private:
    int xpos;
    int ypos;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, dstRect;
};


#endif //TRIANGLE_GAMEOBJECT_H
