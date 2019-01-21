// 2인용 체커 프로그램을 만들어라. 단 플레이어가 기물을 움직일
// 때마다 유효한 동작인지, 언제 게임이 종료되는지 판단해야 한다.
// 왕이 되는 경우를 지원해야 한다.

#include<string>
#include<iostream>

using namespace std;
char chessboard[8][8];
int turn;
int winner;
bool is_empty(int i, int j){

}
bool is_valid_move(int i, int j, int k, int m){
    // is possible to move  (i, j) to (k, m) ?
    // is_empty, by chess rule, KING cannot go to dangerous spot
}

void print_board(){ // 여기도 확장된 사이즈에 맞춰서 재구현 (for 문을 이중으로 열심히 쓰면 될듯)
    int board_size = 8;
    cout << "the current state of the game is as follow: " << endl;
    cout << "┌─";
    string hor = "├";
    for(int i = 0 ; i < board_size-1 ; i++){
        cout << "┬─";
        hor += "─┼";
    }
    hor += "─┤";
    cout << "┐"<<endl;
    for(int i = 0 ; i < board_size ; i++){
        for(int j = 0 ; j < board_size ; j++){
            cout << "│" << (chessboard[i][j]) ;

        }

        cout << "│" <<(char)('a'+i) << endl;
        if(i == board_size-1)
            break;
        cout << hor << endl;
    }
    cout << "└─";
    for(int i = 0 ; i < board_size-1 ; i++){
        cout << "┴─";
    }
    cout << "┘"<<endl;
    for(int i = 0 ; i < 8 ;i++){
        cout << ' ' << (i+1);
    }

}

void setboard(){ // initiallize
// a b c d e f g h
// l n b k q b n l  |1
// p p p p p p p p  |2
//                  |3
//                  |4
//                  |5
//                  |6
// P P P P P P P P  |7
// L N B K Q B N L  |8
    chessboard[0][0] = 'l';
    chessboard[0][1] = 'n';
    chessboard[0][2] = 'b';
    chessboard[0][3] = 'k';
    chessboard[0][4] = 'q';
    chessboard[0][5] = 'b';
    chessboard[0][6] = 'n';
    chessboard[0][7] = 'l';
    for(int i = 0; i < 8; i++){
        chessboard[7][i] = (char)(chessboard[0][i] -32);
        chessboard[1][i] = 'p';
        chessboard[6][i] = 'P';
        for(int j = 2; j < 6 ; j++)
            chessboard[j][i] = ' ';
    }


}



void ended(){
     return;
}

int main(){
    setboard();
    print_board();

}
