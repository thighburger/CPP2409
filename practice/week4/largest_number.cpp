#include <iostream>
using namespace std;
int main(){
int a,b,c,largest;
cout<<"3개의 정수를 입력하시오:";
cin>>a>>b>>c;
if(a>=b&&a>=c)//등호 추가
    largest=a;
else if(b>=a&&b>=c)//등호 추가
    largest=b;
else   
    largest=c;
    cout<<"가장 큰 정수는"<<largest<<endl;
    return 0;
}