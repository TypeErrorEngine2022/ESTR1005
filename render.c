#include "render.h"

const SDL_Color ALIVE_COLOR = {.r = 255, .g = 255, .b = 255}; //white
const SDL_Color DEAD_COLOR = {.r = 0, .g = 0, .b = 0}; //black


void render_cell(SDL_Renderer *renderer, int row, int col, const SDL_Color *color){
    SDL_SetRenderDrawColor(renderer, color -> r, color -> g, color -> b, 255);
    SDL_RenderDrawPoint(renderer, row, col); //Draw on each pixel, one pixel represent one cell
}


void render_board(SDL_Renderer *renderer, const cell *board, const SDL_Color *alive_color, const SDL_Color *dead_color){
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            switch (board[i * SIZE + j].current_state)
            {
            case ALIVE:
                render_cell(renderer, i, j, &ALIVE_COLOR);
                break;
            
            case DEAD:
                render_cell(renderer, i, j, &DEAD_COLOR);
                break;

            default:
                break;
            }
        }
    }
}


void render_game(SDL_Renderer *renderer, const game_t *game){
    render_board(renderer, game -> board, &ALIVE_COLOR, &DEAD_COLOR);
}
