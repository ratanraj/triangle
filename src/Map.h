//
// Created by ratanraj on 25/01/20.
//

#ifndef TRIANGLE_MAP_H
#define TRIANGLE_MAP_H


#include <SDL_rect.h>
#include <SDL_render.h>

class Map {
public:
    Map();
    ~Map();

    void LoadMap(int arr[20][25]);
    void DrawMap();
private:
    SDL_Rect src, dst;
    SDL_Texture *dirt;
    SDL_Texture *grass;
    SDL_Texture *water;

    int map[20][25];
};


#endif //TRIANGLE_MAP_H
