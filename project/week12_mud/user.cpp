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
}

int User::itemCnt() const {
    return cnt; // 아이템 개수 반환
}

ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.itemCnt() << "개 입니다";
    return os;
}

void User::IncreaseCnt(int inc_cnt){
    cnt+=inc_cnt;
}
