

#include <iostream>
using namespace std;

class User {
protected:
    int hp;
    int cnt;

public:
    User();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseCnt(int inc_cnt);
    int GetHP() const;
    int ItemCnt() const;
    void DoAttack();

    friend ostream& operator<<(ostream& os, const User& user);
};
class Magician : User{
    public:
        void DoAttack();
};
class Warrior : User{
    public:
        void DoAttack();
};

