#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
private:
    int hp;
    int cnt;

public:
    User();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseCnt(int inc_cnt);
    int GetHP() const;
    int itemCnt() const;


    friend ostream& operator<<(ostream& os, const User& user);
};

#endif // USER_H
