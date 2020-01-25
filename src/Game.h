//
// Created by ratanraj on 25/01/20.
//

#ifndef TRIANGLE_GAME_H
#define TRIANGLE_GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game {
private:
    bool isRunning;
    SDL_Window *window;

    int cnt = 0;
public:
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

    static SDL_Renderer *renderer;
};


#endif //TRIANGLE_GAME_H
