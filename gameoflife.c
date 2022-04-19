#include <stdio.h>
#include <SDL2/SDL.h>
#include "grid.h"
#include "render.h"
#include "logic.h"


int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return EXIT_FAILURE;

    SDL_Window *window = SDL_CreateWindow("Game of Life", 200, 200, SIZE, SIZE, SDL_WINDOW_SHOWN);

    if (window == NULL) return EXIT_FAILURE;

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL){
        SDL_DestroyWindow(window);
        return EXIT_FAILURE;
    }

    game_t game = {.board = {DEAD}, .state = RUNNING_STATE};

    srand(712); //set different number for seed to generate different initial pattern
    game_init(&game);

    SDL_Event e;
    while (game.state != QUIT_STATE){
        while (SDL_PollEvent(&e)){
            switch (e.type)
            {
            case SDL_QUIT:
                game.state = QUIT_STATE;
                break;

            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        render_game(renderer, &game);
        SDL_RenderPresent(renderer);
        life(&game);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
