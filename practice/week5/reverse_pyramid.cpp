#include <iostream>
using namespace std;
int main(){ 
    int floor;
    cout<<"몇 층을 쌓겠습니까? (5~100):";
    cin>>floor;
    for(int i=floor-1; i>=0; i--)//i초기값 floor-1
    {
        for(int j=0;j<floor-i;j++){
            cout<<"5";
        }
        
        
    
    for(int k=-1;k<i*2;k++)//k초기값 -1
    {
        cout<<"*";
    }
    cout<<endl;
    }
    
    return 0;
}