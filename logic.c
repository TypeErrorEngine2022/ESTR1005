#include "logic.h"


void game_init(game_t *game){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            game -> board[i*SIZE+j].current_state = rand() % 2;	//Initialize each cell to be randomly alive or dead
        }
    }
}

void comp_state(cell *board, int row, int col){
    int ct_alive = 0;
    for (int r = row - 1; r <= row + 1; r++){
        if (r < 0 || r > SIZE - 1) continue; //out of bound
        for (int c = col - 1; c <= col + 1; c++){
            if (c < 0 || c > SIZE - 1) continue; //out of bound
            if (r == row && c == col) continue; //slip itself
            if (board[r * SIZE + c].current_state == ALIVE) ct_alive++;
        }
    }
    if (ct_alive >= 4 || ct_alive <= 1) board[row * SIZE + col].next_state = DEAD; //overpopulation/underpopulation/loneliness
    else if (ct_alive == 3) board[row * SIZE + col].next_state = ALIVE; //birth
    else board[row * SIZE + col].next_state = board[row * SIZE + col].current_state; //statis
}


void life(game_t *game){ //receive 1D array
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            comp_state(game -> board,row, col);
        }
    }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            game -> board[i * SIZE + j].current_state = game -> board[i * SIZE + j].next_state ;
        }
    }
}


