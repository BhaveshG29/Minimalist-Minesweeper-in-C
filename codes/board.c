#include <stdio.h>
#include <string.h>
#include "../libs/board.h"
#include "../libs/game.h"

int arr[10][10];

// 0 for Leaf (Default)
// 1 for Dot
// 2 for Bomb
// 3 for Cherry
// 4 for Red Dot

void initial_Board(){

for(int i=0;i<10;i++){
for(int j=0; j<10;j++){
arr[i][j] = 0;
}
}
}

//Updates the Board as the player inputs.
void update_Board(int row, int col){
marking_bombs();
arr[row][col] = Gamearr[row][col];
}
