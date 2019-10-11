#include "./board/board.hpp"
#include "./board/display.cpp"
#include "./logical/judge.cpp"
#include "./logical/play.cpp"

using std::cin; 
int main(){
    // make a board
    board b;
    player p = player1;
    // set inital row and column
    cout << "please indicate the row and column of board" << endl;
    cin >> ROW >> COLUMN;
    if(ROW < 0 || COLUMN < 0) {
        cout << "The value of ROW and COLUMN should big than zero!";
        return -1;
    }
    while(true){
        cout << "\033[2J\033[1;1H";"]]";
        b.display(); 
        int x, y;
        cout << "player" << p + 1<< " pieces location: (in x, y format)" << endl;
        cin >> x >> y;
        // verificate whether x and y are valid
        if(x >= ROW || x < 0 || y > COLUMN || y < 0) {
            cout << "Pieces cannot given the position out of board!" << endl;
            return -1;
        }
        point c(x,y);
        if(!play(&b, &c, p)) {
            cout << "The position is already used!" << endl;
            return -1;
        }
        terminfo t = b.isterminated();
        if(t.win == true){
            cout << "player" << t.p+1 << "win!" << endl; 
            return 0;
        } 
        p = (p==player1)?player2:player1;
    }
    return -1;
}
