#include "user.h"

ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.ItemCnt() << "개 입니다";
    return os;
}

// Magician 클래스 구현
Magician::Magician() {
    user_name = "M";
    hp=20;
    cnt=0;
    x=0;
    y=0;
}
void Magician::DecreaseHP(int dec_hp) {
    hp -= dec_hp; // HP 감소
}

void Magician::IncreaseHP(int inc_hp) {
    hp += inc_hp; // HP 증가
}

void Magician::IncreaseCnt(int inc_cnt) {
    cnt += inc_cnt;
}

int Magician::GetHP() const {
    return hp;
}

int Magician::ItemCnt() const {
    return cnt;
}
void Magician::DoAttack(){
        cout << "마법 사용!" << endl;
}

// Warrior 클래스 구현
Warrior::Warrior() {
    user_name = "W";
    hp=20;
    cnt=0;
    x=0;
    y=0;
}

void Warrior::DecreaseHP(int dec_hp) {
    hp -= dec_hp; // HP 감소
}

void Warrior::IncreaseHP(int inc_hp) {
    hp += inc_hp; // HP 증가
}

void Warrior::IncreaseCnt(int inc_cnt) {
    cnt += inc_cnt;
}

int Warrior::GetHP() const {
    return hp;
}

int Warrior::ItemCnt() const {
    return cnt;
}
void Warrior::DoAttack(){
        cout << "베기 사용!" << endl;
}