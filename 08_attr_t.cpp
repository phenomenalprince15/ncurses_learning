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
    cbreak(); // for signals like ctrl-c, it's by default too
    // raw(); // handle signals of keyboards
    noecho(); // characters not visible

    if(!has_colors()){
        printw("You can't use colors.");
        getch();
        return -1;
    }
    start_color();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    attr_t emphasis = A_REVERSE | COLOR_PAIR(2);
    attron(emphasis);
    mvaddch(5, 3, 'a');
    mvaddch(5, 4, 'b');
    mvaddch(5, 5, 'c');

    chtype c = 'a' | A_REVERSE | COLOR_PAIR(2);
    mvaddch(5, 12, 'd');

    getch();

    // deallocated ememory and ends ncurses
    endwin();

    return(0);
}
