# 선언하기 
`int array_name[10]; `

여기서
* `int` : int 형으로 이루어진 배열이라는 뜻. 배열은 같은 형의 자료형만 포함할 수 있음. 
* `[10]` : 크기 10이라는 뜻. 이때 0, 1, ..., 9 index 를 가지는 원소들이 있음. 크기는 한번 정하면 바꿀 수 없음 

# 고차원 배열 
`int array[10][10]`

크게 다를 것 없이 비슷함 

# 함수에 배열을 파라미터로 전달할 때 
배열을 파라미터로 받는 함수를 선언할 때는
`int function(int array[]);` 처럼 크기를 지정하지 않은 배열처럼 적는다.

고차원 배열은 `int anotherfunction(int array[][10])` 처럼 첫째 차원 크기 외에는 알려주어야 함 

# 삽입 정렬 
배열 실습 예제

크기 N자리 배열의 [i, N-1] 중 최소값이 i번째에 위치하도록 swap 하는 것을 i= 0 부터 i = N-1 까지 반복하는 알고리즘 

![](https://latex.codecogs.com/svg.latex?O(n^2)) 짜리 시간복잡도 알고리즘. 
시간복잡도상 정렬에서 최적은 ![](https://latex.codecogs.com/svg.latex?O(n\log(n))) 

# 기타 
함수에 배열을 넘겨주면 해당 함수에서 배열을 수정할 때 넘겨줬던 측에서의 배열도 수정되는데 배열이 아닌 경우와는 다르다. 주의가 필요한 듯

포인터와 관련된 내용임. 
```cpp 
#include <iostream>
using namespace std; 
void funct(int a){
  a = 10;
}
void funct2(int a[]){
  a[0] = 10; 
}
int main(){
  int num = 0; 
  int array[10]; 
  for(int i = 0 ; i < 10; i++){
    array[i]=0; 
  }
  funct(num); // funct 에 num 을 넘겨주면 funct 함수 안에서는 a 값이 10으로 바뀜 
  cout << num << endl;  // 그러나 num 은 여전히 처음처럼 0임 
  funct2(array); // 모든 값이 0으로 초기화된 array 를 funct2에 넘겨주면
  cout << array[0] << endl; // 위와는 다르게 funct2 가 실행된 대로 array 도 수정되어 있음 
}
```
