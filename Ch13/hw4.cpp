// 입력 인수 두 개를 받아 두 인수의 곱과 합을 따로 리턴하는 함수를 작성하여라.
// 함수는 하나의 값만을 리턴하므로, 두번째 결과인 두 인수의 합은
// 포인터 혹은 레퍼런스를 파라미터로 사용해야 한다.
// Write a function that takes 2 input args and provides 2 separate resulte to the caller,
// one that is the result of multiplying the 2 args, the other the result of adding them.
// Since you can directly return only 1 value from a function, you'll need the 2nd value
// to be returned through a pointer or reference parameter.

#include <string>
#include <iostream>

using namespace std;

int product_and_sum(int x, int y, int* sum){
    *sum = x+y;
    return x*y;
} // 이렇게 하라는 것이 맞는지? takes 2 args 가 아니고 세번째 arg 를 포인터로 받았음...

int main(){

    int x = 10;
    int y = 20;

    int sum;
    int product = product_and_sum(x, y, &sum);

    cout << sum << " " << product << endl;
}
