#include <iostream>
 using namespace std;
class Animal
 {
 public:
 virtual void Speak(){cout<<"Animalspeak()"<<endl;}
 };
 class Dog:public Animal
 {
 public:
 int age;
 void Speak(){cout<<"멍멍"<<endl;}
 };
 class Cat:public Animal
 {
 public:
 void Speak(){cout<<"야옹"<<endl;}
 };
  int main()
 {
 Animal*a1=new Dog();
 a1->Speak();
 Animal*a2=new Cat();
 a2->Speak();
 Animal*a3=new Animal();
 a3->Speak();
 Animal a4=Cat();
 a4.Speak();//객체슬라이싱됨
delete a1,a2,a3;
 return 0;
 }