// 50개의 값을 넘겨받아 가장 높은 값과 가장 낮은 값, 값들의 평균을
// 출력한 뒤에 한 행에 값 하나씩 출력하는 프로그램을 만들어라.

#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    int size = 10; // 50 으로 고치면 문제에서 요구하는 요건이 됨
    int array[size];
    // srand(time(NULL))
    for(int i = 0 ; i < size ;i ++){
        cin >> array[i] ;
        // array[i] = rand()%(10*size)
        // 직접 입력 받지 않고 임의 초기화 하려면
        // 이 줄 전의 주석처리된 코드로 대체하면 됨
    }

    int max = array[0], min = array[0], sum = 0; // 최대, 최소, 합 초기화
    for(int i = 0 ; i < size ; i++){
        if(max > array[i]){
            max = array[i]; // 기존 최대값보다 더 큰 수 있으면 새 최대값
        }
        if(min < array[i]){
            min = array[i]; // 기존 최소값보다 더 작은 수 있으면 새 최소값
        }
        sum+= array[i]; // 모든 수를 sum 에 더해서 sum 계산
    }
    cout << max << " " << min << " " <<((float)sum / size) << endl;
                        // 최대, 최소, 평균 구하는데 평균은 float으로 캐스팅해서
                        // 나눗셈이 제대로 수행되도록 해야 함
    for(int i = 0 ; i < size; i ++){
        cout << array[i] << endl;
    }

}
