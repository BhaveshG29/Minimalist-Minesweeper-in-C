#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "../libs/game.h"
#include "../libs/board.h"
#include "../libs/scores.h"

bool GameOn = true;
int Gamearr[10][10];

//No. of Bombs
int k;

//User Input Variables
int r,c;
//Function for Scanning User Input
void player_input(){
	printf("Enter the row and column numbers to place your move:");
scanf("%d %d", &r, &c);
r = r-1;
c = c-1;

//Checks if at that position there is a bomb or not
if(Gamearr[r][c]==2){
GameOn = false;
int ret2 = system("clear");
printf("GAME OVER!!!\n");

save_score();
}

//Checks if the Player has Won the Game.
else if(current_score == max_possible_score(2)){
GameOn = false;
int ret3 = system("clear");

printf("Congratulations! %s You've successfully cleared the minefield! %s\n", u8"🎉", u8"🏆");
}

}

//Setting Dots
void equalizing_arr(){
	for(int i=0; i<10;i++){
 for(int j=0; j<10;j++){
Gamearr[i][j] = 1;
 }
 }
}

//Generating K random values to place Bomb and Cherries at K random positions in the Matrix of 10x10
int no_of_bombs(int y){
srand(time(NULL));

y = rand() % (50 - 10 + 1) + 10 + 1; //Minimum of 10 Bombs, maximum of 80 Bombs. No. of Cherry = 1 

return y;
}

//Placing Bombs and Cherry at K-random places
void placing_bombs(){

k = no_of_bombs(0);
    
    srand(time(0));
    
    for (int l = 0; l < k; l++) {
        int i = (rand() % 10);
        int j = (rand() % 10);
	
	if(l==(k-1)){
		Gamearr[i][j] = 3;
	}

	else Gamearr[i][j] = 2;
    }
}


