# 포인터 사용하기 

## 포인터 선언하는 법
포인터 변수 선언하기: (변수 타입) * (변수 이름)
```cpp
int * p_x; 
int* p_y; 
int *p_z; 
int *p_a, *p_b; 
// 모두 가능함. 
// 포인터 변수 이름이 p_ 로 시작해야 한다는 문법은 없음
``` 

## 기존 변수에 활용하는 법: 변수의 주소를 가져오기 
x 라는 정수형 변수가 있고 그 변수의 메모리주소를 가져와서 포인터 변수로 사용하고 싶을 때
```cpp 
int x=10; 
int *p_x = &x; // &x 는 address of x 라고 읽는다 
*p_x = 2; 
// p_x 포인터가 가르키는 값을 2로 업데이트했으므로 x = 2 로 되어 있음 
cout << x << endl; // 2 
cout << p_x << endl; // 어떤 주소값 (매번 다를 것임) 
cout << *p_x << endl; // 포인터 p_x 가 가르키는 값이므로 2 
cout << & x << endl; // 변수 x 가 있는 위치이므로 윗윗줄과 같은 주소값
```

## 포인터 초기화는 NULL 로 
포인터를 초기화하기 전에는 아무 것이나 가르키고 있음. 프로그램이 엉망이 될 수 있기 때문에 반드시 초기화를 해야 함 

그러나 아직 초기화하기 전인 포인터를 사용해야 할 때가 있고 그럴 때는 `NULL`로 초기화하면 된다. 
```cpp
int *p_int = NULL; // p_int 라는 포인터가 가르키는 값을 NULL 로 초기화
if (p_int!= NULL){
	*p_int = 2; 
}
``` 

## 포인터와 함수
지역변수(로컬변수)의 주소를 함수로 전달하면 지역변수를 직접 수정할 수 있음
```cpp
void not_swap(int left, int right){
    int temp = left; 
    left = right; 
    right = temp; 
} // 함수 안에서는 값을 바꾸지만 실제로는 아무 일도 하지 않음 (리턴값이 없으므로) 
void swap(int* p_left, int* p_right){
    int temp = *p_left; 
    *p_left = *p_right; 
    *p_right = temp; 
} // 입력1을 가르키는 포인터와 입력2를 가르치는 포인터를 입력으로 받아서 
  // 포인터가 가르키는 값들을 바꿔주면 
  // 실제로 두 값이 바뀌게 됨

int main(){
    int x = 1, y = 2; 
    swap(&x, &y) // x, y 의 주소를 포인터로 함수에 전달함. 
}
```

## 레퍼런스 
포인터의 간소화 버전. 다른 변수를 가르키는 변수, 그 가르키는 다른 변수와 동일한 메모리 위치를 공유함 

포인터에서의 \*나 & 같은 문법이 필요하지 않음. 단, 레퍼런스를 선언할 때는 앰퍼샌드를 반드시 맨 앞에 붙여야 함. 반드시 초기화해서 사용하기 
```cpp 
int x = 5; 
int &ref = x; 
```

구조체를 함수로 전달하는데 사용하는 예 
```cpp
struct myBigStruct{
    int x[100]; // 메모리가 많이 필요한 큰 구조체
}; 

void takeStruct(myBigStruct& my_struct){
    my_struct.x[0] = 23; 
}
```
스왑 문 레퍼런스로 다시 구현
```cpp
void swap2(int& left, int& right){
    int temp = right; // right 라는 레퍼런스가 가르키는 값을 temp 에 넣어줌
    right = left; 
    left = temp; 
}
int main(){
    int x = 1, y = 2; 
    int& ref_x = x; 
    int& ref_y = y; 
    swap2(ref_x, ref_y); 
    cout << x << " , " << y << endl; 
}

``` 

레퍼런스는 포인터의 대체물임. 변수를 복사하지 않고 함수에 전달하거나, 함수에서 직접 접근하여 파라미터를 수정하여야 할 때 유용함. 

그러나 포인터만큼 유연하지는 않음. 반드시 유효한 메모리 주소를 가르키고 있어야만 하기 때문이다. (`NULL` 을 가르키는 등이 불가능) 한번 초기화되면 레퍼런스는 가르키는 메모리를 변경할 수도 없음 

