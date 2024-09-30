#include <iostream>
using namespace std;
int main(){ 
    int floor;
    cout<<"몇 층을 쌓겠습니까? (5~100):";
    cin>>floor;
    for(int i=1; i<=floor; i++)//i초기값1
    {
        for(int j=0;j<floor-1-i;j++){
        cout<<"S";
        }
    
    for(int k=1;k<i*2;k++)//k초기값1
    {
        cout<<"*";
    }
    cout<<endl;
    }
    
    return 0;
}