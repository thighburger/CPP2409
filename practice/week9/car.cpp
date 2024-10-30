#include<iostream>
#include<string>
using namespace std;
class Car{
public:
 //멤버변수선언
int speed;//속도
int gear;//기어
string color;//색상
//멤버함수선언
void SpeedUp(){//속도증가멤버함수
speed+=10;
 }
 void SpeedDown(){//속도감소멤버함수
speed-=10;
 }
 };
  int main()
 {
 Car myCar;
 myCar.speed=100;
 myCar.gear=3;
 myCar.color="red";
 cout<<"1stspeed:"<<myCar.speed<<endl;
 myCar.SpeedUp();
 cout<<"2ndspeed:"<<myCar.speed<<endl;
 myCar.SpeedDown();
 cout<<"3rdspeed:"<<myCar.speed<<endl;
 return 0;
 }