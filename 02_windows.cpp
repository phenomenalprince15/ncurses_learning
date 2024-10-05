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

    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_y = start_x = 10;
    WINDOW* win = newwin(height, width, start_y, start_x);
    refresh(); // for changes to appeat on screen
    
    // box(win, 102, 102);
    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = (int) 'f';
    top = bottom = 104;
    tlc = trc = blc = brc = (int)'+';
    wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
    // wprintw(win, "Hello box.");
    mvwprintw(win, 1, 1, "Hello box.");
    wrefresh(win); // for window refresh

    int c = getch();
    getch();
    mvprintw(0, 0, "c");
 
    // deallocated ememory and ends ncurses
    endwin();

    return(0);
}
