// 틱택토 프로그램을 만드는 과제
// 두명이 번갈아가면서 틱택토 게임을 하기
// 누가 이겼거나 혹은 비겼는지 ( = 승부가 안 난 채로 모든 칸이 채워짐) 를 판단할 수
// 있도록 코드를 짜라
// 혹시 무승부를 예측할 수 있는지도 생각해보기
// Write a small tic-tac-toe program that allows 2 players
// to play tic-tac-toe competitively. Your program should
// check to see if either player has won, or if the board
// is filled completely (with the game ending in a tie.)
// Bonus. can you make your program detect if the game
// cannot be won by either side before the entire grid is
// filled?

#include <string>
#include <iostream>

using namespace std;

int board[3][3];
// 앞에서 enum 을 쓰라고 제안했었는데 그냥 무시하고 맘대로 짰음
// 1 stands for o (first mover)
// -1 stands for x (second mover)
// 0 stands for empty slot

// 함수 원형 먼저 명세함
void set_game(); // initialize the gameboard.
bool game_ended(); // 호출되면 그 시점에  게임이 승패든 무승부든 끝났는지 판단하여 끝났으면 true를 리턴함
int counter; // 몇 번째 턴인지를 계산. set_game()에서 0으로 초기화되고
            // 한 턴이 진행될 때마다 1 씩 올라감. 9가 되면 게임은 무조건 끝남
bool is_tie; // 비겼으면 true 가 되는 부울리언 전역변수
int turn; // 현재 누구 차례인지 표시함.
            // o 차례이면 1, x 차례이면 -1 .
            // give_turn() 이 수행될 때마다 turn*=-1 되면서 업데이트 됨
int winner();  // o이 이기면 1, x가 이기면 -1을 출력하고 그 외의 경우에는 0
bool fucked(); // 이후로 둘 중 누구도 승리할 수 없는 경우가 되었는지를
                // 판단하여 true 를 반환함
bool told_if_they_were_fucked; // fucked() 가 켜져 있을 때 한번 무승부밖에 가능하지 않다고
                                // 알려준 후로는 다시 그 말을 해줄 필요는 없음
                                // 알려줬는지 여부를 보관하는 전역변수

void print_board(); // 보드의  현상태를 출력해줌
void give_turn(); // 실행되면 누구의 차례인지를 int turn 을 이용해서 읽어내고
                    // 어느 위치에 말을 놓을 것인지를 선택하라고 함.
                    // 만약에 불가능한 위치에 말을 놓으려고 하면 경고 메시지를 줌
                    // 가능한 위치에 말을 놓으면 board 에 저장하고
                    // int turn 을 바꾸어 저장하고 종료
char num2char(int i); // 1 이면 o, -1 이면 x 를 출력해줌. 그 외의 경우에는 띄어쓰기 한 칸을 출력

int main(){
    set_game();
    while(true){
        if(fucked()& !told_if_they_were_fucked){ // 무승부 확정 판정되면 메시지 출력
            cout << "~~~~~ Well, in fact I think you both are fucked. anyway good luck!" << endl;
            told_if_they_were_fucked = true; // 두번 출력되지는 않게 됨
        }
        if(game_ended()){ // 게임 끝났는지 확인
            if(is_tie){ // 비겼을 때
                cout << "~~~~~ End in a tie. Nice play!" << endl;
                print_board();
                break;
            }
            else{ // 누군가 이겼을 때
                cout << "~~~~~~ congrats!! " << num2char(winner()) << " wins" << endl;
                print_board();
                break;
            }
        }
        print_board(); // 현재 보드상태 출력
        give_turn(); // 게임 한 턴 진행
    }


}

void set_game(){
    for(int i = 0 ; i < 3; i++){        // 빈 보드 만들기
        for(int j = 0 ; j < 3 ; j++)
            board[i][j] = 0;
    }
    counter = 0;                        // 이것저것 초기화
    is_tie = false;
    turn = 1;
    told_if_they_were_fucked = false;
}
bool game_ended(){                  // 게임이 끝났습니까?
                                    // 근데 main 함수에서 사용되는 모양을 보니까
                                    // 메인 함수에서도 is_tie 를 따로 판별할 수 있고
                                    // winner()도 어차피 호출하게 될 것이라서
                                    // 이렇게 따로 게임 끝났는지 여부를 확인하는 함수를
                                    // 만드는 것은 낭비네요
                                    // 고치기는 귀찮다
    if(winner() == 1 || winner() == -1)
        return true;
    if (counter == 9){
        is_tie = true;
        return true;
    }
    return false;
}
int winner(){
    for(int i = 0 ; i < 3 ; i ++){ // 각 가로 세로줄이 1로 꽉 차거나 -1로 꽉 차면 승리한다
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0){
            return board[i][0];
        }
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0){
            return board[0][i];
        }
    } // 대각선 두개에 대해서도요
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] != 0){
        return board[1][1];
    }
    if(board[2][0] == board[1][1] && board[0][2] == board[2][0] && board[1][1] != 0){
        return board[1][1];
    }

    return 0; // 아무도 안 이겼을 때는 0 출력
}
void print_board(){ // 예쁘게 출력하려고 고생했음
    cout << "the current state of the game is as follow: " << endl;
    cout << "         " <<  "┌─┬─┬─┐" << endl;
    cout << "         " << "│" << num2char(board[0][0]) << "│" << num2char(board[0][1]) << "│" << num2char(board[0][2]) << "│" << endl;
    cout << "         " << "├─┼─┼─┤" << endl;
    cout << "         " << "│" <<num2char(board[1][0]) << "│" << num2char(board[1][1])<< "│" << num2char(board[1][2]) << "│" << endl;
    cout << "         " << "├─┼─┼─┤" << endl;
    cout << "         " << "│" << num2char(board[2][0]) << "│" << num2char(board[2][1]) << "│" << num2char(board[2][2]) << "│" << endl;
    cout << "         " << "└─┴─┴─┘" << endl;
}
void give_turn(){ // 차례일 때 수를 놓을 수 있게 함
    counter++;
    int i, j;
    cout << num2char(turn) << " 's turn." << endl;
    cout << "put two numbers in {0, 1, 2} to tell the position on you want to put." << endl;

    while(true){ // 잘못된 칸에 놓지 않도록 처리해주는 루프
        cin >> i >>j ;
        if(i>2 || i < 0 || j > 2 || j < 0){
            cout << "the position you requested is out of the board. try again." << endl;
        }
        else if(board[i][j] == 0)
            break;
        else{
            cout << "The position is not available. It is not empty. try again." << endl;
        }
    }
    board[i][j] = turn;

    turn *=-1; // 수를 놓으면 다음 턴에는 다른 사람이 놓게 됨
}
int find_min(int a, int b, int c){ // 보조함수
    int m = a;
    if(m > b)
        m = b;
    if(m > c)
        m = c;
    return m;
}
int find_max(int a, int b, int c){
    int m = a;
    if (m < b)
        m = b;
    if (m < c)
        m = c;
    return m;
}
bool fucked(){
    // 한 행에 1과 -1이 모두 있으면 둘의 차는 2가 되고 이 경우에 이 행을 통해서 승리가 발생할
    // 수는 없음. 열과 대각선에 대해서도 마찬가지
    // 그래서 모든 행, 열, 대각선을 보면서 max-min ==2 인지를 보고 실제로 그렇게 되었으면
    // true 를 출력해주면 됨
    if (told_if_they_were_fucked){ // told_if_they_were_fucked 가 true 인 경우는
                                    // 전에 무승부 판정이 나서 공지해준 경우 뿐이라
                                    //그런 경우에는 이 함수가 별도 판단 없이 true를 리턴하면 됨
        return true;
    }
    for(int i = 0 ; i < 3 ; i ++){
        if(find_max(board[i][0],board[i][1],board[i][2])-find_min(board[i][0],board[i][1],board[i][2])<2)
                return false;
        if(find_max(board[0][i],board[1][i],board[2][i])-find_min(board[0][i],board[1][i],board[2][i])<2)
                return false;

    }
    if( find_max(board[0][0], board[1][1], board[2][2]) - find_min(board[0][0], board[1][1], board[0][2])<2)
        return false;
    if( find_max(board[2][0], board[1][1], board[0][2]) - find_min(board[0][2], board[1][1], board[2][0])<2)
        return false;

    return true;


}

char num2char(int i){ // 1 이면 o, -1 이면 x 를 출력해줌. 그 외의 경우에는 띄어쓰기 한 칸을 출력
    if(i == 1)
        return 'o';
    if(i == -1)
        return 'x';
    if(i == 0)
        return ' ';
    else
        return i;
}
