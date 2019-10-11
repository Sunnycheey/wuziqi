// This source file judge whether a player win the game
#include "../board/board.hpp"

const int NUMBER = 5;
// there is at least five pieces to win;

bool verification(std::vector<point>* p){
    // This function is used for judge whether pieces of one player is connected according to the wuziqi rule
    // for every pieces
    for(auto it = p->begin(); it != p->end(); ++it){
       // for row
       int count = 1;
        for(int i = it->x; i < COLUMN; i++){
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
        for(int i = it->y+1; i < ROW; i++){
            if(count == 5) return true;
            point tmp(it->x, i);
            if(exist(p,&tmp)) count++;
            else{
                count = 1;
                break;
            }
        }
        // for slah relation（斜线的关系）
        for(int i = it->x+1, j = it->y+1; i < ROW && j < COLUMN; i++,j++){
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
terminfo isterminated(board* b){
    // find whether a game is terminated by the status of the game borad
    // find all pieces belongs to player1 and player2
    // return structed data pairs (bool win, player p), if the game is terminated, win is set true and p is set to the winner. win is set false otherwise.
    std::vector<point> p1;
    std::vector<point> p2;
    auto v = b->v;
    for(auto it = v.begin(); it != v.end(); ++it){
       if(it->p == player1) p1.push_back(it->c);
       if(it->p == player2) p2.push_back(it->c);
    }
    // do the verification
    player p = player1;
    if(verification(&p1)) return terminfo(true, p);
    p = player2;
    if(verification(&p2)) return terminfo(true, p);
    return terminfo(false, p);
}
bool exist(std::vector<point>* p, point* c){
    // this function is used to check whether point c is existed in vector p
    for(auto it = p->begin(); it != p->end(); ++it){
        if(it->equal(c)) return true;
    }
    return false;
}
