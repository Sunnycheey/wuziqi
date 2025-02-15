// This file contains the definition of the game board
#ifndef BOARD_HPP
#define BOARD_HPP

#include<vector>

// identify the row and column of board
int ROW;
int COLUMN;
enum player {
    player1, player2
};
class terminfo {
public:
    bool win;
    player p;
    terminfo(bool w, player p): win(w), p(p) {}
};
class point {
public:
    int x;
    int y;
    point(int x, int y) : x(x), y(y) { }
    void set(int x, int y){
        this -> x = x;
        this -> y = y;
    }
    bool equal(point* p){
        return (this->x==p->x)&&(this->y==p->y);
    }
};
class position {
    // this class describe the location and the belonging of one piece
public:
    point c;
    player p;
    position(int x, int y, player p): c(x,y), p(p){ }
};
class board {
    // this class describe the status of board, i.e. full list of pieces
public:
    std::vector<position> v;
    int start_row, start_column, end_row, end_column;
    board(){
       // contructor for board
       // make a empty board
        v.clear();
    }
    // display functino is implemented in display.cpp
    void display();
    terminfo isterminated(); 
    bool haspieces(point *c);
};
bool exist(std::vector<point> *p, point* c);
#endif
