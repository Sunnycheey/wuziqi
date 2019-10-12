// This source file judge whether a player win the game
#include "../board/board.hpp"

using std::vector;

const int NUMBER = 5;
// there is at least five pieces to win;

bool verification(vector<point>* p, int start_row, int start_column, int end_row, int end_column){
    // This function is used for judge whether pieces of one player is connected according to the wuziqi rule
    // for every pieces
    for(auto it = p->begin(); it != p->end(); ++it){
       // for row
       int count = 1;
        for(int i = it->x+1; i < end_row; i++){
            if(count == 5) return true;
            point tmp(i, it->y);
            if(exist(p,&tmp)){
                count++;
            }
            else{
                count = 1;
                break;
            }
        } 
        // for column
        for(int i = it->y+1; i < end_column; i++){
            if(count == 5) return true;
            point tmp(it->x, i);
            if(exist(p,&tmp)) count++;
            else{
                count = 1;
                break;
            }
        }
        // for slah relation（斜线的关系）
        for(int i = it->x+1, j = it->y+1; i < end_row && j < end_column; i++,j++){
            if(count == 5) return true;
            point tmp(i, j);
            if(exist(p, &tmp)) count++;
            else{
                count = 1;
                break;
            }
        }
    }
    return false;
}
terminfo board::isterminated(){
    // find whether a game is terminated by the status of the game borad
    // find all pieces belongs to player1 and player2
    // return structed data pairs (bool win, player p), if the game is terminated, win is set true and p is set to the winner. win is set false otherwise.
    vector<point> p1;
    vector<point> p2;
    for(auto it = v.begin(); it != v.end(); ++it){
       if(it->p == player1) p1.push_back(it->c);
       if(it->p == player2) p2.push_back(it->c);
    }
    // do the verification
    player p = player1;
    if(verification(&p1, start_row, start_column, end_row, end_column)) return terminfo(true, p);
    p = player2;
    if(verification(&p2, start_row, start_column, end_row, end_column)) return terminfo(true, p);
    return terminfo(false, p);
}
bool exist(vector<point>* p, point* c){
    // this function is used to check whether point c is existed in vector p
    for(auto it = p->begin(); it != p->end(); ++it){
        if(it->equal(c)) return true;
    }
    return false;
}
