#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libs/display.h"
#include "../libs/board.h"
#include "../libs/scores.h"
#include "../libs/game.h"

char Bomb[] = u8"💣";
char Cherry[] = u8"🍒";
char Leaf[] = u8"🍀";
char Dot[] = u8"●";


void initial_display(){
int ret = system("clear");

int Max_score = max(12);

//Initial Display
for(int i=0;i<30; i++){
printf("====");
}
printf("\n\t\t\t\t\t\tMINE SWEEPER\n");
for(int i=0;i<30; i++){
printf("====");
}
printf("\n");

//Highest Score Ever Recorded
printf("Highest Score: %d\n\n", Max_score);

printf("Symbols-\n");
printf("Bomb - %s -> Reveal a bomb and you lose the game instantly.\n",Bomb);
printf("Cherry - %s -> Reveal a cherry to gain 100 bonus points!\n", Cherry);
printf("Leaf - %s -> A covered cell on the board (default appearance).\n", Leaf);
printf("Empty - %s -> Uncover an empty cell to earn 10 points.\n", Dot);
printf("\n\n");
}

//Displaying Board and Score Simultaneously 
void display(){
	for(int i=0; i<10; i++){
	printf("\t\t");
	for(int j=0;j<10; j++){
if(arr[i][j]==0) printf("%s\t", Leaf);
else if(arr[i][j]==1) printf("%s\t", Dot);
else if(arr[i][j]==2) printf("%s\t", Bomb);
else if(arr[i][j]==3) printf("%s\t", Cherry);
else printf("X\t");
}
printf("\n\n");
}

printf("Score: %d\n\n", current_score);
}
