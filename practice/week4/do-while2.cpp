#include <iostream>
using namespace std;
int main(){
  int choice;
  cout<<"do-while문을 사용하여 메뉴선택:"<<endl;
  do{
    cout<<"메뉴를 선택하세요(1.옵션,2.옵션2,3.종료):";
    cin>>choice;
    
    switch(choice){
        case 1:
            cout<<"옵션 1선택"<<endl;
            break;
        case 2:
            cout<<"옵션 2선택"<<endl;
            break;
        case 3:
            cout<<"프로그램 종료"<<endl;
        default:
            cout<<"잘못된 선택"<<endl;
            break;
    }

  }while(choice!=3);
    return 0;
}