//
// Created by ratanraj on 25/01/20.
//

#include <iostream>
#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "GameObject.h"

GameObject *player;
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

    player = new GameObject("assets/mon.png", 0, 0);
    map = new Map();
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
                case SDLK_UP:
                    player->changeDirection(GameObject::DIR_UP);
                    break;
                case SDLK_DOWN:
                    player->changeDirection(GameObject::DIR_DOWN);
                    break;
                case SDLK_LEFT:
                    player->changeDirection(GameObject::DIR_LEFT);
                    break;
                case SDLK_RIGHT:
                    player->changeDirection(GameObject::DIR_RIGHT);
                    break;
            }
            break;
        default:
            break;
    }
}

void Game::update() {
    cnt++;
    player->Update();

    std::cout << cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    // this is where we add stuff to render
    map->DrawMap();
    player->Render();

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
