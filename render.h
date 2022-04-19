#ifndef RENDER
#define RENDER

#include <SDL2/SDL.h>
#include "grid.h"

 
void render_game(SDL_Renderer *renderer, const game_t *game);

#endif