#include <iostream>
using namespace std;
int main(){
    int x,y;
    cout <<"x값을 입력하시오: ";
    cin>>x;
    cout<<"y값을 입력하시오 ";
    cin>>y;
    if(x>y)
        cout <<"x가y보다 큽니다."<<endl;
    else if(x==y)
        cout <<"x와y는 같습니다.";
    else
        cout<<"y가x보다 큽니다."<<endl;
    return 0;
}