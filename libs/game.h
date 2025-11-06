#include <stdbool.h>
#include <time.h>
#ifndef GAME_H
#define GAME_H

extern bool GameOn;
extern int Gamearr[10][10];
extern int k;

extern int r,c;
void player_input();

void equalizing_arr();

int no_of_bombs(int y);
void placing_bombs();

#endif
