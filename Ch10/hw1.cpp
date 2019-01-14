// 앞에서 구현했던 삽입 정렬 코드를 insertion_sort 라는 함수로 변환하라. 단 배열의 크기를
// 가리지 않고 작업할 수 있는 함수여야 한다.

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

// 함수에서 array 를 수정하면 원래 array 도 변경된다는 것을 몰랐는데
// 생각해 보니까 배열을 리턴할 필요가 없고 그냥 void 형으로 함수를 만들었어도 됨.
int* insertion_sort(int array[], int size){ // 배열을 리턴하는 법을 잘 모르겠음
                                            // 검색한 대로 짜니까 되기는 하는데 포인터
                                            // 부분에서 자세히 배워야 할 것 같습니다
    int temp; // swap 함수를 따로 구현하지 않고 소트함수 안에서 swap 함
    for(int i = 0; i< size; i++){
        for(int j = i ; j < size ; j ++){
           if(array[i] < array[j]){ // 이중 for문을 돌면서 i번째 스텝에선 0~i번째까지가 잘
                                    // 정렬되어 있도록 짜면 됨
                                    // i번째 수부터 끝까지 중 최대인 수가 i번째에 위치하도록
                                    // 필요한 경우 swap을 해줍니다
                                    // 이중 for문이기 때문에 O(n^2/2) = O(n^2)
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
    int size;
    cin >> size;
    int array[size];
    for(int i = 0 ; i < size ; i++){
        array[i] = rand() % (size); // 임의 초기화
        cout << i << "th : < " << array[i]<<endl;
    }
    int* sorted_array = insertion_sort(array, size);
    for(int i = 0 ; i < size ; i ++) // 정렬 결과 단순 출력
        cout << sorted_array[i]<< " ";

}
