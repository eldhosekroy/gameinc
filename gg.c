#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <pthread.h>
#define win 3

int x, y, hor, ver, loss=1,score,ver1,hor1;

void *loop1(void *arg) {
    while (1) {
        ver1 = 0, hor1;
        srand(time(0));
        hor1 = rand() % x;
        srand(rand());
        for (int i = 0; i <= y; i++) {
            clear();
            ver1++;
            mvprintw(ver1, hor1, "*");

            // Check if the plate caught the falling *
            if (ver1 == ver && hor1 >= hor && hor1 <= hor + 2) {
                score++;
            }else if(ver1 == ver){
	    loss--;
	    }

            mvprintw(ver, hor, "===");
            mvprintw(0, 0, "Score: %d", score);
	    mvprintw(2, 0, "Life : %d",loss);
            refresh();
            usleep(200000);
        }


	 if (score == win) {
            mvprintw(y / 2, x / 2 - 4, "You win!");
            break;
	 }/*else if(loss == 0){
	 	mvprintw(y / 2 , x / 2 - 5,"You loss!");
		break;
	 }*/


    }
    pthread_exit(NULL);
}

void *loop2(void *arg) {
    int key;
    while (1) {
        key = getch();
        if (key == KEY_RIGHT && hor != x - 3) {
            clear();
            hor++;
        } else if (key == KEY_LEFT && hor != 0) {
            clear();
            hor--;
        }
	mvprintw(ver1,hor1,"*");
        mvprintw(ver, hor, "===");
        mvprintw(0, 0, "Score: %d", score);
	mvprintw(2, 0, "Life : %d",loss);
        refresh();


	 if (score == 3) {
    	    mvprintw(y / 2, x / 2 - 4, "You win!");
            break;
	 }/*else if(loss == 0){
                mvprintw(y / 2 , x / 2 - 5,"You loss!");
                break;
         }*/


    }
    

    pthread_exit(NULL);

}

int main() {
    initscr();
    curs_set(0);
    keypad(stdscr, 1);

    getmaxyx(stdscr, y, x);
    ver = y - 1;
    hor = x / 2;
    score = 0;
    mvprintw(ver, hor, "===");
    mvprintw(0, 0, "Score: %d", score);

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, loop1, NULL);
    pthread_create(&thread2, NULL, loop2, NULL);

    while (1){
     if (score == 3) {
            mvprintw(y / 2, x / 2 - 4, "You win!");
            break;
     }/*else if(loss == 0){
                mvprintw(y / 2 , x / 2 - 5,"You loss!");
                break;
         }*/
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);


    mvprintw(y /2 ,x /2 ,"loss");

    endwin();
    return 0;
}

