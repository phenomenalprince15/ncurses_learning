#include <iostream>
#include <ncurses.h>
#include <cstring>
#include <vector>

using namespace std;

class Player {
    public:
        Player(WINDOW* win, int y, int x, char c);

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        int getMove();
        void display();
    

    private:
        int xLoc, yLoc, xMax, yMax;
        char character;
        WINDOW* currWin;

};

Player::Player(WINDOW* win, int y, int x, char c) {
    currWin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(currWin, yMax, xMax);
    keypad(currWin, true);
    character = c;
}

void Player::moveUp() {
    mvwaddch(currWin, yLoc, xLoc, '.'); // To hide character after move, using '. to see what's going on
    yLoc--;
    if (yLoc < 1) yLoc = 1;
}

void Player::moveDown() {
    mvwaddch(currWin, yLoc, xLoc, '.');
    yLoc++;
    if (yLoc > yMax-2) yLoc = yMax-2;
}

void Player::moveLeft() {
    mvwaddch(currWin, yLoc, xLoc, '.');
    xLoc--;
    if (xLoc < 1) xLoc = 1;
}

void Player::moveRight() {
    mvwaddch(currWin, yLoc, xLoc, '.');
    xLoc++;
    if (xLoc > xMax-2) xLoc = xLoc-2;
}

int Player::getMove() {
    int choice  = wgetch(currWin);

    switch(choice) {
        case KEY_UP:
            moveUp();
            break;
        case KEY_DOWN:
            moveDown();
            break;
        case KEY_LEFT:
            moveLeft();
            break;
        case KEY_RIGHT:
            moveRight();
            break;
    }
    return choice;
}

void Player::display() {
    mvwaddch(currWin, yLoc, xLoc, character);
}

int main(int argc, char** argv) {

    // initialized the screen.
    initscr();
    cbreak(); // for signals like ctrl-c, it's by default too
    // raw(); // handle signals of keyboards
    noecho(); // characters not visible

    int y, x, xbeg, ybeg, ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    WINDOW* playwin = newwin(20, 50, (ymax/2)-10, 10);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    keypad(playwin, true);

    Player* p = new Player(playwin, 1, 1, '@');
    // while(p->getMove() != 'x'){
    //     p->display();
    //     wrefresh(playwin);
    // }

    do{ // to show player befre, pint before we start to play
        p->display();
        wrefresh(playwin);
    } while(p->getMove() != 'x');

    getch();

    // deallocated ememory and ends ncurses
    endwin();

    return(0);
}
