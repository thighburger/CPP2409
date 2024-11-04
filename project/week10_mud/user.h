#include<iostream>
using namespace std;
class User{
private:
	int hp;
public:
	void DecreaseHP(int dec_hp){hp-=dec_hp;}
	void IncreaseHP(int inc_hp){hp+=inc_hp;}
	int GetHP(){return hp;}
	User(){hp=20;}
};