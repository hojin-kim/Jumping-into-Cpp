#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

bool if_sorted(int array[], int size){
    // 오름차순으로 정렬되었는지 확인
    if(size <= 1){
        return true;
    }
    for(int i = 0 ; i < size-1 ; i ++){ // 연이은 두 수의 대소관계가 모두 맞으면 됨
        if(array[i] > array[i+1])
            return false;
    }
    return true;
}

int* bubblesort(int array[], int size){ // hw1에서의 정렬 알고리즘 그대로 사용
    for(int i = 0; i < size; i++){
        for(int j= i; j< size; j++){
            if(array[i]>array[j]){
                int temp;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}

int main(){
    srand(time(NULL));
    int size = 100;
    int a[size];
    for(int i = 0; i < size; i++){  // initialize by random integers;
                                    // or you can use any other initialization by
                                    // modifying this block
        a[i] = rand()%200;
    }
    int* b ;                        // 아직 포인터 모름 ㅋㅋ
    if(!if_sorted(a, size))
        b = bubblesort(a, size);
    else
        b = a;

    for(int i = 0 ; i < size ; i++){
        cout << b[i] << " " ;
    }
}
