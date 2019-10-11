// ncurses is used as UI in terminal
#include "board.hpp"
#include <iostream>
#include <ncurses.h>
#include "../logical/play.cpp"

using std::cout; using std::endl; using std::vector;
void board::display(){
    // this function is used to display the game board
    // we use * to represent the blank position of board, + represent the pieces of player1 and - represent the pieces of player2.
    vector<point> p1;
    vector<point> p2;
    player user = player1;
    for(auto it = v.begin(); it != v.end(); ++it){
       if(it->p == player1) p1.push_back(it->c);
       if(it->p == player2) p2.push_back(it->c);
    }
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    // make an original board
    // int row, column;
    // getmaxyx(stdscr, row, column);
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            mvaddch(i, j, '*');
        }
    }
    // set the position of cursor to (0, 0)
    move(0,0);
    refresh();
    while(true){
        int ch = getch();
        point p(0,0);
        switch(ch){
            case KEY_LEFT:
                // move the window to left by one unit
               getyx(stdscr, p.x, p.y);
               if(p.y != 0) move(p.x, p.y-1);
               refresh();
               // else do nothig
                break;
            case KEY_RIGHT:
                getyx(stdscr, p.x, p.y);
                if(p.y != COLUMN-1) move(p.x, p.y+1);
                refresh();
                break;
            case KEY_UP:
                getyx(stdscr, p.x, p.y);
                if(p.x != 0) move(p.x-1, p.y);
                refresh();
                break;
            case KEY_DOWN:
                getyx(stdscr, p.x, p.y);
                if(p.x != ROW-1) move(p.x+1, p.y);
                refresh();
                break;
            case 10:
                // case 10 represent enter
                getyx(stdscr, p.x, p.y);
                if(user == player1) {
                    addch('+');
                }
                else if(user == player2) {
                    addch('-');
                }
                if(!play(this, &p, user)){
                    return ;
                    endwin();
                }
                terminfo t = this->isterminated();
                if(t.win == true){
                    endwin();
                    return;
                }
                refresh();
                user = (user==player1)?player2:player1;
                break;
        }
    }
    endwin();
}
