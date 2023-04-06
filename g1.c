#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
//#include<time.h>
void fall(int x,int y){
	int hor1,ver1=0;
 		srand(time(0));
                hor1=rand()%x;
                srand(rand());
                for(int i=0;i<=y;i++){
                clear();
                ver1++;
                mvprintw(ver1,hor1,"*");
                refresh();
                usleep(200000);
                }
}

int main() {
    initscr();
    curs_set(0);

    int x, y;
    getmaxyx(stdscr, y, x);
    int ver = y - 2, hor = x / 2;
	//int ver1=y,hor1;
    //mvprintw(ver, hor, "__");

  //  for(;;){
   // }
    int key;
    while (1) {
    //fall(x,y);
        key = getch();
	if(key==67&&hor!=x-3){
		clear();
	hor++;
	}else if(key==68 && hor!=0){
		clear();
	hor--;
	}
	mvprintw(ver,hor,"__");


	//for(;;){
	//fall(x,y);
	//}

        refresh();
    } 

    endwin();
    return 0;
}

