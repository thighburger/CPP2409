#include <iostream>
using namespace std;

int main(){
    const int maxPeople=5;
    string names[maxPeople];
    int ages[maxPeople];
    cout<<maxPeople<<"명의 회원 정보를 입력해주세요."<<endl;

    int max=0;
    int min=10000;

    string old;
    string young;

    for(int i=0;i<maxPeople;i++){
        cout <<"사람"<<i+1<<"의 이름:";
        cin>>names[i];
        cout<<"사람" <<i+1<<"의 나이:";
        cin >>ages[i];
    if(max<ages[i]){
            max=ages[i];
            old=names[i];
            }
    if(min>ages[i]){
            min=ages[i];
            young=names[i];
            }
    }
  
 

    int choice;
    while(1){
    cout<<"1.가장 나이가 많은 사람 출력"<<endl<<"2.가장 나이가 적은 사람 출력"<<endl<<"3.종료";
    cin >>choice;
    if(choice==1)
        cout<<old<<endl;
    else if(choice==2)
        cout<<young<<endl;
    else {  
        cout<<"종료";
        break;
        }
    
    
    }
    }
   

    
    

    
