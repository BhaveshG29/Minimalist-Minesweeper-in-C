//This file was to finalize the Design of the game.


#include <stdio.h>
#include <stdlib.h>

//Displays the Design
int main(){
int ret = system("clear");
int Max_score =9999;
//Title
for(int i=0;i<30; i++){
printf("====");
}
printf("\n\t\t\t\t\t\tMINE SWEEPER\n");
for(int i=0;i<30; i++){
printf("====");
}
printf("\n");

printf("Highest Score: %d\n\n", Max_score);

char Bomb[] = u8"💣";
char Cherry[] = u8"🍒";
char Leaf[] = u8"🍀";
char Dot[] = u8"●";

printf("Symbols-\n");
printf("Bomb - %s -> If found this you lose the game.\n",Bomb);
printf("Cherry - %s -> If found this Score increase by 100 points\n", Cherry);
printf("Leaf - %s -> Defualt Board Look\n", Leaf);
printf("Empty - %s -> If found this Score increases by 10 points\n", Dot);
printf("\n\n");



for(int i =0; i<10;i++){
	printf("\t\t%d ", i+1);
for(int j =0; j<10;j++){

if(i==5 && j==3) printf("%s\t", Cherry);
else if(i%5 == 0 && j%3==0) printf("%s\t", Bomb);
else printf("%s\t", Leaf);
}
printf("\n\n");
}

int r,c;
printf("User Input:");
scanf("%d %d", &r, &c);
r = r-1;
c=c-1;

for(int i =0; i<10;i++){
	printf("\t\t%d ", i+1);
for(int j =0; j<10;j++){

if(i==5 && j==3) printf("%s\t", Cherry);
else if(i%5==0 && j%3==0) printf("%s\t", Bomb);
else if(i==r && j==c) printf("%s\t", Dot);
else printf("%s\t", Leaf);
}
printf("\n\n");
}

return 0;
}
