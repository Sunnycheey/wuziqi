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
    // set the board to center of stdscr
    int row, column;
    getmaxyx(stdscr, row, column);
    start_row = row/2-ROW/2; start_column = column/2-COLUMN/2;
    end_row = row/2+ROW/2; end_column = column/2+COLUMN/2;
    mvprintw(start_row-2, start_column, "Player %d:", user+1);
    for(int i = start_row; i < end_row; i++){
        for(int j = start_column; j < end_column; j++){
            mvaddch(i, j, '*');
        }
    }
    // set the position of cursor to the start of board
    move(start_row, start_column);
    refresh();
    while(true){
        int ch = getch();
        point p(0,0);
        switch(ch){
            case KEY_LEFT:
            case 'h':
                // move the window to left by one unit
               getyx(stdscr, p.x, p.y);
               if(p.y != start_column) move(p.x, p.y-1);
               else{
                   // move cursor to the upper rightmost position
                   if(p.x-1 != start_row) move(p.x-1, end_column); 
               }
               refresh();
                break;
            case KEY_RIGHT:
            case 'l':
                getyx(stdscr, p.x, p.y);
                if(p.y != end_column) move(p.x, p.y+1);
                else{
                    if(p.x+1 != end_row) move(p.x+1, start_column);
                }
                refresh();
                break;
            case KEY_UP:
            case 'k':
                getyx(stdscr, p.x, p.y);
                if(p.x != start_row) move(p.x-1, p.y);
                refresh();
                break;
            case KEY_DOWN:
            case 'j':
                getyx(stdscr, p.x, p.y);
                if(p.x != end_row) move(p.x+1, p.y);
                refresh();
                break;
            case 'q':
                endwin();
                return;
            case 10:
            case ' ':
                // represent enter key
                getyx(stdscr, p.x, p.y);
                if(!play(this, &p, user)){
                    mvprintw(start_row-1, start_column, "The location is aldreay used! press any key to continue");
                    move(p.x, p.y);
                    refresh();
                    getch();
                    move(start_row-1, start_column);
                    // clear line
                    clrtoeol();
                    move(p.x, p.y);
                    refresh();
                    continue;
                }
                if(user == player1) {
                    addch('+');
                }
                else if(user == player2) {
                    addch('-');
                }
                terminfo t = this->isterminated();
                if(t.win == true){
                    // print win information
                    mvprintw(start_row-1, start_column, "Game over, Winner is: Player %d", t.p+1);
                    refresh();
                    getch();
                    endwin();
                    return;
                }
                user = (user==player1)?player2:player1;
                mvprintw(start_row-2, start_column, "Player %d:", user+1);
                move(p.x, p.y);
                refresh();
                break;
        }
    }
    endwin();
}
