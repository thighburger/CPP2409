#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str)
{
    for(int i=0;i<str.length();i++)
        str[i]=tolower(str[i]);
    return str;
}
string toUpperStr(string str)
{
    for(int i=0;i<str.length();i++)
        str[i]=toupper(str[i]);
    return str;
} 
int calcHammingDist(string s1, string s2)
{   
    int count=0;
    while(s1.length() !=s2.length())
    {
        cout<<"문자열을 다시 입력해주세요:"<<endl;
        cout<<"첫 번째 문자열을 입력해주세요: ";
        cin>>s1;
        cout<<"두 번째 문자열을 입력해주세요: ";
        cin>>s2;
    }
    for(int i=0; i<s1.length();i++){

        if(toLowerStr(s1)[i]!=toLowerStr(s2)[i])
            count+=1;
    }
    return count;
}
int main(){   
    string s1,s2;
    cout<<"첫 번째 문자열을 입력해주세요: ";
    cin>>s1;
    cout<<"두 번째 문자열을 입력해주세요: ";
    cin>>s2;
    int count=calcHammingDist(s1,s2);
    cout<<"해밍 거리는 "<<count<<endl;
    return 0;
}