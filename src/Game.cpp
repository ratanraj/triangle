//
// Created by ratanraj on 25/01/20.
//

#include <iostream>
#include "Game.h"
#include "TextureManager.h"
#include "Map.h"

SDL_Texture *playerTex;
SDL_Rect srcR, dstR;

Map *map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = SDL_WINDOW_SHOWN;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_VIDEO)==0){
        std::cout << "SDL Subsystems initialized" << std::endl;
        window = SDL_CreateWindow(title, xpos,ypos, width, height, flags);
        if(window) {
            std::cout << "Window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!"<<std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }

    playerTex = TextureManager::LoadTexture("assets/mon_right.png");
    map = new Map();
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
        default:
            break;
    }
}

void Game::update() {
    cnt++;
    dstR.h=32;
    dstR.w = 32;

    dstR.x = cnt;

    std::cout << cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    // this is where we add stuff to render
    map->DrawMap();
    SDL_RenderCopy(renderer, playerTex, NULL, &dstR);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

bool Game::running() {
    return isRunning;
}
