//
// Created by ratanraj on 25/01/20.
//

#ifndef TRIANGLE_GAMEOBJECT_H
#define TRIANGLE_GAMEOBJECT_H


#include <SDL_render.h>

class GameObject {
public:
    GameObject(const char *textureSheet, int x, int y);
    GameObject();
    ~GameObject();

    void Update();
    void Render();

    void changeDirection(int dir);

    const static int DIR_UP = 0;
    const static int DIR_DOWN = 1;
    const static int DIR_LEFT = 2;
    const static int DIR_RIGHT = 3;

private:
    int xpos;
    int ypos;
    int direction;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, dstRect;
};


#endif //TRIANGLE_GAMEOBJECT_H
