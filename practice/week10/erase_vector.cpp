 #include <vector>
 #include <iostream>
 using namespace std;
 int main(void) {
 
 vector<int> v;
 for (int i = 0; i < 10; ++i) {
    v.push_back(i);
 }
 cout << "현재의 v= ";
 for (auto& e : v)
    cout << e << " ";
 cout << endl;
 v.erase(v.begin()+5);
 cout << "5번 인덱스를제거한후v= ";
 for (auto& e : v)
    cout << e << " ";
 cout << endl;
 return 0;
 }