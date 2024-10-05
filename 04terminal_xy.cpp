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

    int y, x, xbeg, ybeg, ymax, xmax;
    getyx(stdscr, y, x); // param - window, y, x ---> we can replace stdscr with win also
    getbegyx(stdscr, ybeg, xbeg);
    getmaxyx(stdscr, ymax, xmax);

    // printw("%d %d %d %d %d %d", y, x, ybeg, xbeg, ymax, xmax);
    // mvprintw(ymax/2, xmax/2, "Hello");
    mvprintw(ymax/2, xmax/2, "%d %d", ybeg, xbeg);

    getch();

    // deallocated ememory and ends ncurses
    endwin();

    return(0);
}
