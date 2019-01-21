#include <string>
#include <iostream>

using namespace std;

int main(){
    int first_int = 10;
    int second_int = 20;
    cout << "두 주소를 오름차순으로 (작은 것부터) 출력하기 " << endl << "(주소에 따라서 값도 밑에 출력해보면...)"<< endl;
    if(&first_int < &second_int){
        cout << &first_int << " , " << &second_int<< endl;
        cout << first_int<< " , " << second_int;
    }
    else{
        cout << &second_int << " , " << &first_int<< endl;
        cout << second_int << " , " << first_int ;
    }
}
// 반복해서 실행해 봐도 first_int 의 주소값이 (nonsense 같지만 주소값을 숫자로 생각하면)
// 더 작고 그래서 먼저 출력됨. 그 다음이 second_int 인데 딱 4칸 차이가 남. int 가 4byte 라서
