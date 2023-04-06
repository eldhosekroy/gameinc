#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <pthread.h>
//#include<time.h>

void *fall(void *arg) {
    int x = *((int *)arg);
    int y = *((int *)arg+1);
    int hor1, ver1=0;
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
    pthread_exit(NULL);
}

int main() {
    initscr();
    curs_set(0);

    int x, y;
    getmaxyx(stdscr, y, x);
    int ver = y - 2, hor = x / 2;
    //int ver1=y,hor1;
    //mvprintw(ver, hor, "__");

    pthread_t thread;
    int thread_args[2] = {x, y};
    pthread_create(&thread, NULL, fall, (void *)thread_args);

    int key;
    while (1) {
        key = getch();
        if(key==67&&hor!=x-3){
            clear();
            hor++;
        }else if(key==68 && hor!=0){
            clear();
            hor--;
        }
        mvprintw(ver,hor,"__");

        refresh();
    }

    pthread_join(thread, NULL);
    endwin();
    return 0;
}

