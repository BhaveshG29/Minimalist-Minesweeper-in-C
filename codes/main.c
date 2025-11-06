#include <stdio.h>
#include <string.h>
#include "../libs/display.h"
#include "../libs/board.h"
#include "../libs/game.h"
#include "../libs/scores.h"


int main(){

initial_Board();
initial_display();


printf("\n\n\n");
equalizing_arr();
placing_bombs();
display(); 

while(GameOn){
player_input();
if((r>=0 && r<=9) && (c>=0 && c<=9) && arr[r][c]==0){

update_Board(r,c);
update_score();
display();
}

else if(((r<0 || r>9) || (c<0 || c>9)) || (arr[r][c] ==1 || arr[r][c] == 2)){
printf("Plese Enter Valid Values of row and column!!\n\n");
}

}

return 0;
}
