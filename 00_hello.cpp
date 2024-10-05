#include <iostream>
#include <ncurses.h>

using namespace std;

int main(int argc, char** argv) {

    // initialized the screen.
    initscr();

    printw("Hello world!");

    // refreshes the screen to match whats in memory
    refresh();

    // whats for user input, returns int value to that way
    int c = getch();
    printw("%d", c);

    // getch();

    endwin();
    // deallocated ememory and ends ncurses

}
