#include "../board/board.hpp"
#include <iostream>

bool haspieces(board *b, point *c){
    for(auto it = b->v.begin(); it != b->v.end(); ++it){
        if(it->c.equal(c)) return true;
    }
    return false;
}
bool play(board* b, point* c, player p){
    // point p represent the desired position
    if(haspieces(b, c)) return false;
    position newposition(c->x, c->y, p); 
    b->v.push_back(newposition);
    return true;
}
