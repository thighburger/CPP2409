#include <iostream>
#include <string>
#include <vector>
using namespace std;

// User 클래스를 추상 클래스로 변경 (인터페이스처럼 동작)
class User {
public:
    int hp;
    int cnt;
    int x, y;
    string user_name;

    virtual void DoAttack() = 0; // 순수 가상 함수 (추상 메서드)
    virtual void DecreaseHP(int dec_hp) = 0;
    virtual void IncreaseHP(int inc_hp) = 0;
    virtual int GetHP() const = 0;
    virtual void IncreaseCnt(int inc_cnt) = 0;
    virtual int ItemCnt() const = 0;
    friend ostream& operator<<(ostream& os, const User& user);
    virtual ~User() {}  // 가상 소멸자
    
};

// Magician 클래스
class Magician : public User {
public:
    Magician();
    void DoAttack() override ;
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override ;
    int GetHP() const override ;
    void IncreaseCnt(int inc_cnt) override ;
    int ItemCnt() const override ;
};

// Warrior 클래스
class Warrior : public User {
public:
    Warrior();
    void DoAttack() override ;
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override ;
    int GetHP() const override ;
    void IncreaseCnt(int inc_cnt) override ;
    int ItemCnt() const override ;
};