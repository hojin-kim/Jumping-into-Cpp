// 3*3 보다 큰 tictactoe
// 승리조건 : 한 열, 행, 주대각선들에 4개 이상의 기호가 일치하면
// 해당 기호가 나타내는 사람이 승리
// 비길 수밖에 없다고 알려주는 함수는 구현하지 않음
// 구조는 거의 비슷함
#include <string>
#include <iostream>

using namespace std;

int board[1000][1000]; // 나중에 사용자 입력을 1000 이하의 수로 받아서
                        // 해당하는 크기의 subarray 만을 고려할 것임

void set_game(int size_input);
bool game_ended();
int board_size;
// int counter; 이거 쓰는거 좀 안좋은 느낌 들어서 hw5 에서는 안 썼음

bool is_tie;

int turn;

int winner();
char num2char(int i){ // 1 이면 o, -1 이면 x 를 출력해줌
    if(i == 1)
        return 'o';
    if(i == -1)
        return 'x';
    if(i == 0)
        return ' ';
    else
        return i;
}
void print_board();
void give_turn();
int main(){
    int size_input;
    cout << "set the size of the board." << endl;
    cin >> size_input;
    set_game(size_input);
    while(true){
//        if(fucked()& !told_if_they_were_fucked){
//            cout << "~~~~~ Well, in fact I think you both are fucked. anyway good luck!" << endl;
//            told_if_they_were_fucked = true;
//        }
        if(game_ended()){
            if(is_tie){
                cout << "~~~~~ End in a tie. Nice play!" << endl;
                print_board();
                break;
            }
            else{ // means somebody wins
                cout << "~~~~~~ congrats!! " << num2char(winner()) << " wins" << endl;
                print_board();
                break;
            }
        }
        print_board();
        give_turn();
    }


}

void set_game(int size_input){
    for(int i = 0 ; i < size_input; i++){
        for(int j = 0 ; j < size_input ; j++)
            board[i][j] = 0;
    }
    is_tie = false;
    turn = 1;
    board_size = size_input;
//    told_if_they_were_fucked = false;
}
bool game_ended(){
    if(winner() == 1 || winner() == -1)
        return true;
    for(int i = 0 ; i < board_size ; i++){
        for(int j=0; j <board_size; j++){
            if(board[i][j] ==0)
                return false;
        }
    }
    is_tie = true;
    return true;
}
int winner(){ // 여기는 확장된 크기에 맞춰서 구현
    // o 가 이겼으면 1
    // x 가 이겼으면 -1
    // 그렇지 않으면 0 출력
    int count_o = 0;
    int count_x = 0;
    for(int i = 0 ; i < board_size ; i++){
        for(int j = 0 ; j < board_size; j++){ // 가로줄이나 세로줄에서 연속한 4개가 일치하면 되니까
                                                // 연속하는 동안만 count 를 올려서 4가 되면
                                                // 승리판정을 해주면 됨
                                                // 카운터가 4가 아닐 때 연속 조건이 깨지면 카운터는
                                                //다시 0으로 리셋하면 됩니다
            if(board[i][j] == 1)
                count_o++;
            else
                count_o = 0;

            if(board[i][j] == -1)
                count_x++;
            else
                count_x = 0;

            if(count_o == 4)
                return 1;
            if(count_x == 4)
                return -1;
        }
        count_o =0;
        count_x =0;

    }
    for(int j = 0 ; j < board_size ; j++){
        for(int i = 0 ; i < board_size; i++){
            // 위 이중루프 transpose
            if(board[i][j] == 1)
                count_o++;
            else
                count_o = 0;

            if(board[i][j] == -1)
                count_x++;
            else
                count_x = 0;

            if(count_o == 4)
                return 1;
            if(count_x == 4)
                return -1;
        }
        count_o =0;
        count_x =0;

    }
    for(int i = 0 ; i < board_size ; i++){
        if(board[i][i] == 1)
            count_o++;
        else
            count_o = 0;
        if(board[i][i] ==-1)
            count_x++;
        else count_x = 0 ;

        if(count_o == 4)
            return 1;
        if(count_x == 4)
            return -1;
    }
    count_o = 0;
    count_x = 0;
    for(int i = 0 ; i < board_size ; i++){
        if(board[i][board_size-1-i] == 1)
            count_o++;
        else
            count_o = 0;
        if(board[i][board_size-1-i] ==-1)
            count_x++;
        else count_x = 0 ;

        if(count_o == 4)
            return 1;
        if(count_x == 4)
            return -1;
    }
    return 0;
}
void print_board(){ // 여기도 확장된 사이즈에 맞춰서 재구현
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
            cout << "│" << num2char(board[i][j]) ;
        }
        cout << "│" << endl;
        if(i == board_size-1)
            break;
        cout << hor << endl;
    }
    cout << "└─";
    for(int i = 0 ; i < board_size-1 ; i++){
        cout << "┴─";
    }
    cout << "┘"<<endl;

    return;
}
void give_turn(){
    int i, j;
    cout << num2char(turn) << " 's turn." << endl;
    cout << "put two numbers among 0 to " << board_size-1 << " to indicate the position on you want to put." << endl;

    while(true){
        cin >> i >>j ;
        if(i>board_size-1 || i < 0 || j > board_size-1 || j < 0){ // 여기만 고쳤음.
            cout << "the position you requested is out of the board. try again." << endl;
        }
        else if(board[i][j] == 0)
            break;
        else{
            cout << "The position is not available. It is not empty. try again." << endl;
        }
    }
    board[i][j] = turn;

    turn *=-1;
}
/*
int find_min(int a, int b, int c){
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
    // for 문의 각 스텝에서 판단하는 좆된여부를 따로 입력을 subboard로 받는  함수로
    // 빼서 해도 될텐데 지금 버전도 번거롭긴 하지만 그래도 이게 낫다고 판단
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

*/
