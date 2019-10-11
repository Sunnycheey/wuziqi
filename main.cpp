#include "./board/board.hpp"
#include "./board/display.cpp"
#include "./logical/judge.cpp"
#include "./logical/play.cpp"

int main(){
    // make a board
    board b;
    player p = player1;
    while(true){
        std::cout << "\033[2J\033[1;1H";"]]";
        b.display(); 
        int x, y;
        std::cout << "player" << p + 1<< " pieces location: (in x, y format)" << std::endl;
        std::cin >> x >> y;
        // verificate whether x and y are valid
        if(x >= ROW || x < 0 || y > COLUMN || y < 0) {
            std::cout << "Pieces cannot given the position out of board!" << std::endl;
            return -1;
        }
        point c(x,y);
        if(!play(&b, &c, p)) {
            std::cout << "The position is already used!" << std::endl;
            return -1;
        }
        terminfo t = b.isterminated();
        if(t.win == true){
            std::cout << "player" << t.p+1 << "win!" << std::endl; 
            return 0;
        } 
        p = (p==player1)?player2:player1;
    }
    return -1;
}
