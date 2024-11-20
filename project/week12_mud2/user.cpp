#include "user.h"

void User::DecreaseHP(int dec_hp) {
    hp += dec_hp; // HP 감소
    
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp; // HP 증가
    
}

int User::GetHP() const {
    return hp;
}

User::User() {
    hp = 20;
    cnt = 0;
    x=0;
    y=0;
}

int User::ItemCnt() const {
    return cnt; // 아이템 개수 반환
}

ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.ItemCnt() << "개 입니다";
    return os;
}

void User::IncreaseCnt(int inc_cnt){
    cnt+=inc_cnt;
}
void User:: DoAttack(){
    cout<<"공격합니다";
}

//Magician,Warrior
void Magician::DoAttack(){
    cout<<"마법 사용";
}
void Warrior::DoAttack(){
    cout<<"베기 사용";
}
