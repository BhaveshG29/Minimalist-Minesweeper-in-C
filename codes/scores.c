#include <stdio.h>
#include "../libs/scores.h"
#include "../libs/game.h"

#define MAX_SIZE 10000

int current_score = 0;

//Finds and Returns  the max possible score of that game.
int max_possible_score(int possible){ 

possible = 1090 - 10*k;

return possible;
}


//Locating the Highest Score in scores.dat file
int max(int useless){
useless = useless - 1; //No Use

FILE *score;
score = fopen("../scores.dat", "r");

if(score==NULL){ 
	printf("Error No file named 'scores.dat' found.");
	printf("\nCreating a new 'scores.dat' file\n\n");
	score = fopen("../scores.dat", "w");
return -409;
}

int M_arr[MAX_SIZE];
int maximum = -2123;
int idx = 0;

while(idx<MAX_SIZE && (fscanf(score, "%d", &M_arr[idx])==1)){
idx++;
}

for(int i=0; i<idx; i++){
if(M_arr[i]>maximum){ 
	maximum = M_arr[i];
}
}

fclose(score);

return maximum;
}

//Simultaneously Updates the score
void update_score(){

if(Gamearr[r][c]==1 || Gamearr[r][c] == 4) current_score += 10;
if(Gamearr[r][c]==3) current_score += 100;
else current_score += 0;

}

//Saves the Game Score after the game ends
void save_score(){
FILE *save;

save = fopen("../scores.dat", "a");

if(save==NULL){
save = fopen("../scores.dat", "w");
}


if(current_score >= 100) fprintf(save,"%d\n", current_score);
fclose(save);

printf("\n\nThank You for playing\n\n");
}
