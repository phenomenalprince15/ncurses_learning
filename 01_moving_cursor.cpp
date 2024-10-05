#include <iostream>
#include <ncurses.h>

using namespace std;

/*
Cursor starts at (0, 0) of screen.
Let's move it.
*/
int main(int argc, char** argv) {

    // initialized the screen.
    initscr();

    int x=5, y=15;
    move(y, x); // y is row and x is col
    printw("Hello world!");

    // whats for user input, returns int value to that way
    int c = getch();
    move(0, 0);
    printw("%d", c);
    getch();

    endwin();
    // deallocated ememory and ends ncurses

}
