#include <iostream>
#include <string>
#include <vector>
using namespace std;

// User 클래스를 추상 클래스로 변경 (인터페이스처럼 동작)
class User {
protected:
    int hp;
    int cnt;
    int x, y;

public:
    string user_name;
    virtual void DoAttack() = 0; // 순수 가상 함수 (추상 메서드)

    virtual void DecreaseHP(int dec_hp) = 0;
    virtual void IncreaseHP(int inc_hp) = 0;
    virtual int GetHP() const = 0;
    virtual void IncreaseCnt(int inc_cnt) = 0;
    virtual int ItemCnt() const = 0;

    virtual ~User() {}  // 가상 소멸자
};

// Magician 클래스
class Magician : public User {
public:
    Magician() {
        hp = 30;
        cnt = 0;
        x = 0;
        y = 0;
        user_name = "Magician";
    }

    void DoAttack() override {
        cout << "마법 사용!" << endl;
    }

    void DecreaseHP(int dec_hp) override {
        hp -= dec_hp;
    }

    void IncreaseHP(int inc_hp) override {
        hp += inc_hp;
    }

    int GetHP() const override {
        return hp;
    }

    void IncreaseCnt(int inc_cnt) override {
        cnt += inc_cnt;
    }

    int ItemCnt() const override {
        return cnt;
    }
};

// Warrior 클래스
class Warrior : public User {
public:
    Warrior() {
        hp = 40;
        cnt = 0;
        x = 0;
        y = 0;
        user_name = "Warrior";
    }

    void DoAttack() override {
        cout << "베기 사용!" << endl;
    }

    void DecreaseHP(int dec_hp) override {
        hp -= dec_hp;
    }

    void IncreaseHP(int inc_hp) override {
        hp += inc_hp;
    }

    int GetHP() const override {
        return hp;
    }

    void IncreaseCnt(int inc_cnt) override {
        cnt += inc_cnt;
    }

    int ItemCnt() const override {
        return cnt;
    }
};