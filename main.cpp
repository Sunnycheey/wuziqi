#include "./board/board.hpp"
#include "./board/display.cpp"
#include "./logical/judge.cpp"

using std::cin; 
int main(){
    // make a board
    board b;
    cout << "please indicate the row and column of board" << endl;
    cin >> ROW >> COLUMN;
    if(ROW < 0 || COLUMN < 0) {
        cout << "The value of ROW and COLUMN should big than zero!";
        return -1;
    }
    while(true){
        /* int x, y; */
        /* // verificate whether x and y are valid */
        /* if(x > b.end_row || x < b.start_row || y > b.end_column || y < start_column) { */
        /*     cout << "Pieces cannot given the position out of board!" << endl; */
        /*     return -1; */
        /* } */
        b.display();
    return -1;
    }
}
