#include<vector>
 #include<iostream>
 using namespace std;
 int main(void){
 vector<int>v;
 for(int i=0;i<10;++i){
 v.push_back(i);
 }
 cout<<"현재의v= ";
 for(auto&e:v)
 cout<<e<<"";
 cout<<endl;
 //it의타입은vector<int>::iterator
 auto it=v.begin()+5;
 v.insert(it,100);
 cout<<"5번인덱스에값을추가한후v= ";
 for(auto&e:v)
 cout<<e<<"";
 cout<<endl;
 return 0;
 }