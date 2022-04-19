#ifndef GRID
#define GRID

#define ALIVE 1
#define DEAD 0

#define RUNNING_STATE 0
#define QUIT_STATE 1

#define SIZE 400


//Assume we are trying n^2 grid

typedef struct cell{
    int current_state;
    int next_state;
}cell;


typedef struct game{
    cell board[SIZE * SIZE];
    int state;
} game_t;

#endif 