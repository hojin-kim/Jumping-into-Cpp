## 구조체 
여러 자료형 데이터 묶어서 관리하기 
```cpp
struct person{
  int no; 
  string name; 
  int weight; 
  int height; 
  bool is_happy; 
};
``` 
이름, 체중, 몸무게, 행복 여부를 묶어서 관리할 수 있다. 중괄호 닫고 ;를 반드시 붙여야 ㅏㅁㅎ

이때 name, weight 등을 필드라고 부름 

## 구조체 사용하기 
```cpp 
person hey; 
hey.name = "hojin"; 
```
그런데 이 책에서 설명하는 것과 보통 사용되는 형태가 다른 것 같음. 보통은 구조체를 사용한다고 알려주는 struct 키워드가 필요함 
```cpp 
struct person hey; 
hey.name = "hojin"; 
``` 
혹은 구조체를 선언할 때부터 별명을 정해주면 ```struct ``` 가 필요없음. 
```cpp
typedef struct person{
  int no; 
  string name; 
  int weight; 
  int height; 
  bool is_happy; 
} per; 
per hey; 
hey.name = "hojin; 
```
초기화를 간편하게 할 수도 있음
```cpp 
per hey = {.no =1, .name = "hojin", .weight = -1, .height = -1, is_happy = false}; 
```
혹은
```cpp
per hey = {0, }; // 모두 0으로 초기화. string 형인 name은 "" (빈 스트링)으로 초기화되는 것 같음 
``` 
초기화 내용과 ```typedef``` 등의 내용은 책에는 없음 
