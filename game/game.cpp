
#include <SDL.h>
#include <iostream>
#include "player.h"

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 600;

bool init(SDL_Window*& window, SDL_Renderer*& renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    window = SDL_CreateWindow("跑跑馬力歐", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void close(SDL_Window*& window, SDL_Renderer*& renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Color red = { 255, 0, 0 };
    Player player(100, 500, 50, 50, 1, red);
    if (!init(window, renderer)) {
        return -1;
    }


    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }


        const Uint8* keyState = SDL_GetKeyboardState(nullptr);
        player.move(keyState, SCREEN_WIDTH, SCREEN_HEIGHT);

        // 清空畫面
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // 背景黑色
        SDL_RenderClear(renderer);

        // 渲染主角
        player.render(renderer);

        // 更新畫面1
        SDL_RenderPresent(renderer);
    }


    close(window, renderer);
    return 0;
}