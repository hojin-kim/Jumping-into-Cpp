#include <string>
#include <iostream>
using namespace std;

// 사용자에게서 게임 점수를 입력받음
// 적절한 구조체를 만들어서 정보 저장
// 저장되어야 하는 정보 : (사용자 이름, 사용자가 한 게임의 점수들)
// 지원해야 하는 기능 : 사용자마다 최고 점수, 특정 사용자 점수 전체, 사용자 리스트

struct user{
    string name;
    int max_score;
    int num_games;
    int scores[1000]; //1000 판으로 게임 점수 저장 용량  제한

};

// 사용자리스트는 전역변수로 관리
user userlist[1000]; // 천 명까지로 제한
int num_user = 0;
void register_score(){
    string name;
    int score;
    cout << "사용자 이름을 알려주세요" << endl;
    cin >> name;
    cout << "점수를 적어주세요." << endl;
    cin >> score;
    for(int i =0 ; i < num_user; i++){
        if(userlist[i].name ==name){ // 이미 자기 점수가 등록된 적 있는 사람이
                                    // 새로운 점수를 등록하는 상황
                                    //
            userlist[i].scores[userlist[i].num_games] = score;
            for(int j = 0; j < userlist[i].num_games; j++)
                if (userlist[i].max_score < score)
                    userlist[i].max_score = score;
            userlist[i].num_games ++;
            return;
        }
   }
    struct user adding  = {name, score, 1, };
    adding.scores[0] = score;
    userlist[num_user] = adding;
    num_user++;
    cout << "새로운 사용자로 등록되었습니다." << endl;

}

void print_user_list(){
    for(int i = 0 ; i < num_user ; i ++){
        cout <<userlist[i].name << " " ;
    }
    cout << endl;
}
void print_max_scores(){
    for(int i = 0 ; i < num_user ; i ++){
        cout << userlist[i].name << " 의 최고점수는 " << userlist[i].max_score << "입니다."
            << endl;
    }
}
void print_scores_for_someone(){
    cout << "점수 목록을 보고 싶은 사용자는 누구인가요?" << endl;
    string name;
    cin >> name;
    for(int i = 0 ; i < num_user ; i++){
        if(userlist[i].name == name){
            cout << name << " 의 점수 목록은 다음과 같습니다. " << endl;
            for(int j = 0 ; j < userlist[i].num_games; j++){
                cout << userlist[i].scores[j] << " " ;
            }
            cout << endl;
            return;
        }
    }
    cout << "그런 이름은 목록에 없습니다. " << endl;

}
int main(){
    while(true){
        cout << ">> 당신의 점수를 저장하고 싶으면 1을 입력하세요. " << endl <<
            ">> 각 사용자의 최고점수를 알고 싶으시면 2를 입력하세요. " << endl<<
            ">> 특정 사용자의 점수들을 모두 보시려면 3을 입력하세요. " << endl<<
            ">> 사용자 리스트를 보고 싶으시면 4를 입력하세요. " << endl <<
            ">> 프로그램을 종료하시려면 0을 눌러주세요." << endl;
        int menu;
        cin >> menu;
        if (menu == 0)
            break;
        switch(menu){
            case 1:
                register_score();
                break;
            case 2:
                print_max_scores();
                break;
            case 3:
                print_scores_for_someone();
                break;
            case 4:
                print_user_list();
                break;
            default:
                cout << "try again" << endl;


        }

    }
    cout << "프로그램을 종료합ㄴ디ㅏ...";
}
