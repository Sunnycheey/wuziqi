#include "board.hpp"
#include <iostream>

void display(board* b){
    // this function is used to display the game board
    // we use * to represent the blank position of board, + represent the pieces of player1 and - represent the pieces of player2.
    std::vector<point> p1;
    std::vector<point> p2;
    auto v = b->v;
    for(auto it = v.begin(); it != v.end(); ++it){
       if(it->p == player1) p1.push_back(it->c);
       if(it->p == player2) p2.push_back(it->c);
    }
    // using a two dimensional char array to represent the board
    char game_board[ROW][COLUMN];
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            game_board[i][j]='*';
        }
    }
    for(auto it = p1.begin(); it != p1.end(); ++it){
        game_board[it->x][it->y] = '+';
    }
    for(auto it = p2.begin(); it != p2.end(); ++it){
        game_board[it->x][it->y] = '-';
    }
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            std::cout << game_board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
