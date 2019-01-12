#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct spaceShip{
int x_pos;
int y_pos;
};
spaceShip my_ship; // 걍 전역변수로 관리하려고 함
void set_ship(){
    srand(time(NULL));
    my_ship.x_pos = rand()%1024;
    my_ship.y_pos = rand()%768;
}
bool is_spaceship_in_the_screen(spaceShip a){
    if(a.x_pos <0 || a.x_pos >1023)
        return false;
    if(a.y_pos<0 || a.y_pos>767)
        return false;
    return true;
}
spaceShip update_position(spaceShip ship){ // 어떻게 업데이트 하라는 지시가 없음
                                    // 1~50 중의 랜덤한 수로 각각 x좌표와
                                    // y 좌표 값을 더해서 위치 업데이트 하기
    srand(time(NULL));

    spaceShip return_ship;
    return_ship.x_pos = ship.x_pos + rand()%100 +1;
    return_ship.y_pos = ship.y_pos + rand()%70 +1;
    return return_ship;
}
void print_ship(spaceShip a){
    cout << "now the ship is at (" << a.x_pos << " , " << a.y_pos << ")." << endl;
}
int main(){
    set_ship();
    cout << "Your ship is now set." << endl;
    print_ship(my_ship);
    while(is_spaceship_in_the_screen(my_ship)){
       my_ship =  update_position(my_ship);
       print_ship(my_ship);
    }
    cout <<"now  your ship is out of the screen." ;
}
