#include <string>
#include <iostream>

using namespace std;

struct userinfo{
    string number;
    string name;
    string address; // 010-1111-1111 를 생각하면 정수형으로 받기에는 전화번호의 크기나
                  // 첫자리 0 문제 등 때문에 적절하지 않음.
}; // 구조체 블록 닫을 때는 세미콜론 필요

struct contact_list{
    int size_of_the_users;
    userinfo contacts[100]; // 항목의 수가 100으로 제한됨.
    // 항목의 수를 제한하지 않기 위해
    // 연락처 수가 일정한 수를 넘어서면 userinfo[] 의 수를 두배로 늘리는 식의
    // 구현을 생각했는데, userinfo[] 배열의 크기는 고정되어 있어야 함
    // int size_of_the_phonebook; userinfo contacts[size_of_the_phonebook]; 과 같은
    // 구현을 해 두고 필요할 때 size 를 증가시키고 contacts 를 갱신해서 관리하려고도
    // 해보았는데 역시 안됨.
    // flexible array 라는 것이 있기는 한 것 같은데 이 수준에서 다룰 수 있는
    // 문법을 뛰어넘는 것 같음
};

contact_list set_phonebook(){
    struct contact_list mylist = {0, };
    // 책에는 서술되어 있지 않은것 같은데 구조체로 된 변수를 이렇게 초기화할 수도 있는 것 같음
    return mylist;
}
contact_list register_user(contact_list mylist, userinfo user){
    mylist.contacts[mylist.size_of_the_users] = user;
    mylist.size_of_the_users++;
    return mylist;
}
void print_list(contact_list mylist){
    for(int i = 0; i < mylist.size_of_the_users; i++){
        cout << i+1  << " user:"<<endl; ;
        cout << "number: " << mylist.contacts[i].number << endl;
        cout << "name: " << mylist.contacts[i].name << endl;
        cout << "address: " << mylist.contacts[i].address << endl;
        cout << " ------ " << endl;
    }

}
int main(){
    struct contact_list mylist;
    mylist = set_phonebook();

    cout << "Phonebook was set." << endl;
    while(true){
        cout << "input 1 to register new user; 2 to print all users; and 0 to quit." << endl;
        int menu;
        cin >> menu;
        if(menu == 0){ // while 문 안에 있는 switch 문에서는 break문을 통해 while 문에서
                    // 벗어날 수 없음. 그래서 따로 if 문으로 뺐습니다.
                    // switch 문의 defaul case 를 사용하기 위해서는 switch 문보다 앞에
                    // 있어야 함

            cout << "program shutting down.." << endl;
            break;
        }
        switch(menu){
            case 1:{
                string number;
                string name;
                string address;
                cout << "input your number, name, address respectively." << endl;
                cin >> number >> name >> address;
                struct userinfo adding = {number, name, address};
                mylist = register_user(mylist,adding);
                break;
            }
            case 2:{
                print_list(mylist);
                break;
            }
            default:
                cout << "try again" << endl;
        }
    }
}
