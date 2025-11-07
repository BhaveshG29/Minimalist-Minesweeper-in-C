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

char s[10];

//Asks the play if he/she wants to replay the game.
void replay(){
printf("Type 'yes' to play again:");
scanf("%s", s);
//fgets(s,sizeof(s), stdin);
 s[strcspn(s, "\n")] = 0;
if(strcmp(s,"yes")==0 || strcmp(s,"Yes")==0 || strcmp(s,"y")==0 || strcmp(s,"Y")==0 || strcmp(s,"YES")==0){
int ret5 = system("clear");
int ret6 = system("make run");
}
else{ 
	int ret7 = system("make clean");
	printf("Thank You for Playing!\n");
}
}

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
		Gamearr[i][j] = 3; //Cherry
	}

	else Gamearr[i][j] = 2; //Bombs
    }
}

//Showing Red Dots if there is a bomb near that dot. Can be on the diagonal, ahead/back/up/down.
void marking_bombs() {
    int i, j, x, y;
    
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (Gamearr[i][j] == 2) {
                
                int directions[8][2] = {
                    {-1, -1}, {-1, 0}, {-1, 1},  // Top-left, Top, Top-right
                    {0, -1},   /*aij */    {0, 1},    // Left, Right
                    {1, -1},  {1, 0},  {1, 1}     // Bottom-left, Bottom, Bottom-right
                };
                
                for (int k = 0; k < 8; k++) {
                    x = i + directions[k][0];
                    y = j + directions[k][1];
                    
                    if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                if (Gamearr[x][y] != 2 && Gamearr[x][y] != 3) {
                            Gamearr[x][y] = 4;
                        }
                    }
                }
            }
        }
    }
}

