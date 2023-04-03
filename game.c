#include<stdio.h>
#include"myh.h"
//#include<conio.h>
void hide_c(){
	printf("\033[?25l");
}

void clear(){
	printf("\033[2J");
}

void move_c(int a,int b ){
	printf("\033[%d;%dH",a,b);
}

void show_c(){
	printf("\033[?25h");
}

void print(char snake[]){
	printf("%s",snake);
}

/*void keypress(){
	char key;
	key=getc();
	printf("%c is key",key);
}
*/


int main(){
clear();
int x,y;
tc_get_cols_rows(&y,&x);
move_c(x/2,y/2);
char snake[]="0ooooo";
print(snake);
}


//printf("Hello");


/*

   ANSI escape codes
hide cursor     \033[?25l
show cursor   \033[?25h
clear                 \033[2J
move cursor    \033[1;1H

*/
