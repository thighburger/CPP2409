#include <iostream>
using namespace std;
#include <string>


 class Rectangle {
 public:
 int width, height;
 int CalcArea() {
 return width * height;
 }
 };


 int main() {

 Rectangle obj1;
 Rectangle obj2;

 obj1.width = 3;
 obj1.height = 4;

 obj2.width = 10;
 obj2.height = 10;

 int area = obj1.CalcArea();
 int area2= obj2.CalcArea();
 cout << "사각형1의 넓이: " << area << endl;
 cout<<"사각형2의 넓이: "<<area2<<endl;
 return 0;
 }