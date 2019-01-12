#include <string>
#include <iostream>

using namespace std;

struct userinfo{
string number;
string name;
string address; // 010-1111-1111 를 생각하면 정수형으로 받기에는 전화번호의 크기나
                // 첫자리 0 문제 등 때문에 적절하지 않음.
}; // 구조체 블록 닫을 때는 세미콜론 필요

int main(){
    userinfo a;
    cout << "input your infos. what is your name?" << endl;
    cin >> a.name;
    cout << "and what is your address?" << endl;
    cin >> a.address;
    cout << "finally tell me your number." << endl;
    cin >> a.number;
    cout << "thanks. so your name is " << a.name << " , \
address is " << a.address << " , and number is " << a.number << "." << endl;

}
