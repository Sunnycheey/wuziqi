#include "../board/board.hpp"

bool board::haspieces(point *c){
    for(auto it = v.begin(); it != v.end(); ++it){
        if(it->c.equal(c)) return true;
    }
    return false;
}
bool play(board* b, point* c, player p){
    // point p represent the desired position
    if(b->haspieces(c)) return false;
    position newposition(c->x, c->y, p); 
    b->v.push_back(newposition);
    return true;
}
