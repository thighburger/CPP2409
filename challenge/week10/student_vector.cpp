#include <vector>
#include <iostream>
using namespace std;
int main(void) {
    int sum=0;
    int score;
    vector<int> student;
    while(true){
        cout<<"성적을 입력하시오(종료는 -1) : ";
        cin>>score;
        if(score==-1){
            break;
        }
        student.push_back(score);
        
    }
    for(int i:student){
        sum+=i;
    }
    float average=sum/student.size();
    cout<<"성적 평균="<<average;
}