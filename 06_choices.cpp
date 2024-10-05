#include <iostream>
#include <ncurses.h>
#include <cstring>
#include <vector>

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

    WINDOW* menuwin = newwin(6, xmax-12, ymax-5, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);

    string choices[3]= {"walk", "jog", "run"};
    int choice;
    int highlight = 0;

    while(1) {
        for (int i=0; i<3; i++) {
            if( i == highlight)
                wattron(menuwin, A_REVERSE); // highlight reveers fg and bg
            mvwprintw(menuwin, i+1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);
        switch(choice) {
            case KEY_UP:
                highlight--;
                if(highlight == -1) highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 3) highlight = 2;
                break;
            default:
                break;
            }

            if (choice == 10) {
                break;
            }
        }
        printw("your choice was: %s", choices[highlight].c_str());

    getch();

    // deallocated ememory and ends ncurses
    endwin();

    return(0);
}
