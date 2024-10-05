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

    /*
    A_NORMAL
    A_STANDOUT
    A_BLINK
    A_DIM
    A_BOLD
    A_PROTECT
    A_INVIS
    A_ALTCHARSET
    A_CHARTEXT
    */

    // attron(A_BLINK);
    // printw("This is some text.");
    // attroff(A_BLINK);

    // getch();
    
    /*
    COLOR_PAIR(n)
    COLOR_BLACK 0
    COLOR_RED 1
    COLOR_GREEN 2
    yellow 3
    blue 4
    magenta 5
    cyan 6
    white 7
    */

    // 1 is id
    init_pair(1, COLOR_CYAN, COLOR_WHITE); // or use init_color(COLOR_CYNA, 0-999, 0-999, 0-999)
    if (can_change_color()) {
        printw("can change color.");
        init_color(COLOR_CYAN, 9,9, 9);
    }
    attron(COLOR_PAIR(1)); // pair is foreground and background color
    printw("Hello there, how are you ???");
    attroff(COLOR_PAIR(1));

    getch();

    // deallocated ememory and ends ncurses
    endwin();

    return(0);
}
