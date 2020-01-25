//
// Created by ratanraj on 25/01/20.
//

#ifndef TRIANGLE_TEXTUREMANAGER_H
#define TRIANGLE_TEXTUREMANAGER_H


#include "Game.h"

class TextureManager {
private:
public:
    static SDL_Texture* LoadTexture(const char *texture);
    static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst);
};


#endif //TRIANGLE_TEXTUREMANAGER_H
