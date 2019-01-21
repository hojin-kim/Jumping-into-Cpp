// 사용자에게 성을 입력하라고 항상 표시하는 대신, 콜러가 성에 해당하는
// 포인터로 NULL 을 전달할 때만 입력을 요구하도록 실습 문제 1번 함수를 수정하여라

// 근데 문제가 이해가 안 가는 점이 있는데...
// NULL 포인터를 전달받으면 그 포인터는 아무것도 가르키고 있지 않는데
// 이름 입력을 요구받으면 입력받은 이름을 어떻게 저장하지??
// NULL 이 아닐 때만 입력을 요구하는게 아닐까?
#include <string>
#include <iostream>

using namespace std;
void input_name_by_pointer(string *p_first, string *p_last){
    cout << "input name by pointer." << endl << "성" << endl;
    cin >> *p_first;
    if(p_last != NULL){
//  if(p_last == NULL) 문제가 잘못되지 않았다면 이렇게 해두면 되지만..
        cout << "이름" <<endl;
        cin >> *p_last;
    }
}

int main(){
    string first_name;
    string last_name;
//     string* pointer_last_name = NULL;
    string *pointer_last_name =&last_name;
    input_name_by_pointer(&first_name, pointer_last_name);
    cout << first_name<< endl;
    cout << last_name << endl;
}
