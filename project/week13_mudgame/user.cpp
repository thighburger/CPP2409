#include "user.h"

ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.ItemCnt() << "개 입니다";
    return os;
}

// Magician 클래스 구현
Magician::Magician() : hp(20), cnt(0), x(0), y(0) {
    user_name = 'M';
}

void Magician::DecreaseHP(int dec_hp) {
    hp -= dec_hp; // HP 감소
    if (hp < 0) hp = 0; // HP가 0보다 작아지지 않도록 설정
}

void Magician::IncreaseHP(int inc_hp) {
    hp += inc_hp; // HP 증가
    if (hp > 100) hp = 100; // HP가 100을 초과하지 않도록 설정
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

void Magician::DoAttack() const {
    cout << "마법 사용" << endl;
}

// Warrior 클래스 구현
Warrior::Warrior() : hp(20), cnt(0), x(0), y(0) {
    user_name = 'W';
}

void Warrior::DecreaseHP(int dec_hp) {
    hp -= dec_hp; // HP 감소
    if (hp < 0) hp = 0; // HP가 0보다 작아지지 않도록 설정
}

void Warrior::IncreaseHP(int inc_hp) {
    hp += inc_hp; // HP 증가
    if (hp > 100) hp = 100; // HP가 100을 초과하지 않도록 설정
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

void Warrior::DoAttack() const {
    cout << "베기 사용" << endl;
}
