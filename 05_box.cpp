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
    getmaxyx(stdscr, ymax, xmax);

    WINDOW* inputwin = newwin(6, xmax-12, ymax-5, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);

    keypad(inputwin, true);

    int c = wgetch(inputwin);
    // if(c == 'q') {
    //     mvwprintw(inputwin, 1, 1, "You pressed q!");
    //     wrefresh(inputwin);
    // }
    if(c == KEY_UP) {
        mvwprintw(inputwin, 1, 1, "You pressed Up key!");
        wrefresh(inputwin);
    }

    getch();

    // deallocated ememory and ends ncurses
    endwin();

    return(0);
}
