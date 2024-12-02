#include "user.h"
#include <iostream>
#include <string>
#include<vector>
#include <fstream>
#include<sstream>
using namespace std;

User *user;// User 객체생성

const int mapX = 5;
const int mapY = 5;
bool inMap;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>>map, int user_x, int user_y);
bool checkGoal(vector<vector<int>>map, int user_x, int user_y);
void checkState(vector<vector<int>>map, int user_x, int user_y);

// 사용자의 입력을 저장할 변수(전역변수로이동)
string user_input = "";

//맵벗어났는지 체크함수
void is_in(int user_x,int user_y){
		inMap = checkXY(user_x, mapX, user_y, mapY);
		if (inMap == false) {
			cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
			if(user_input=="up")
				user->y+=1;
			if(user_input=="down")
				user->y-=1;
			if(user_input=="left")
				user->x+=1;
			if(user_input=="right")
				user->x-=1;
			}
}
//bool CheckUser(User user) 함수 생성
bool CheckUser(User* user){
	if(user->GetHP()<=0){
		return false;
	}
	else{
		return true;
	}

}

// 메인  함수
int main() {

	ifstream file("map.txt"); 
	if (!file) { 
		throw runtime_error("파일을 열 수 없습니다."); 
	} 
	vector<vector<int>> map(mapY, vector<int>(mapX)); 
	for (int i = 0; i < mapY; ++i) { 
		for (int j = 0; j < mapX; ++j) { 
			file >> map[i][j]; 
		} 
	} 
	file.close();
	
	int choice;
	
	// 1202 예외추가
	try
    {
    	cout<<"직업을 선택하세요.(마법사:1,전사:2)"<<endl;
    	cin>>choice;
		if(choice!=1 && choice!=2)
			throw choice;
	}
	catch(int e)
	{
		cout<<"올바른 입력이 아닙니다.";
		return 0;
	}
	

	if(choice==1){
		cout<<"마법사를 선택하셨습니다"<<endl;
		user=new Magician();
	}
	else if(choice==2){
		cout<<"전사를 선택하셨습니다"<<endl;
		user=new Warrior();
	}
	
	
	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		
		//hp 출력하는부분객체의GetHP멤버함수호출로진행
		cout << "현재 HP: "<< user->GetHP() <<"  명령어를 입력하세요 (up,down,left,right,map,finish,information,attack): ";
		cin >> user_input;

		if (user_input == "up") {
			// 위로 한 칸 올라가기
			user->y -= 1;

			is_in(user->x,user->y);
			if(inMap==true) {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user->x, user->y);
				checkState(map, user->x, user->y);//호출
				user->DecreaseHP(1);//hp 감소되는부분객체의DecreaseHP 멤버함수호출로진행
			}
		}
		else if (user_input == "down") {
			// TODO: 아래로 한 칸 내려가기
			user->y += 1;

			is_in(user->x,user->y);
			if(inMap==true) {
				cout << "위로 한 칸 내려갑니다." << endl;
				displayMap(map, user->x, user->y);
				checkState(map, user->x, user->y);

				user->DecreaseHP(1);
			}
		}

		else if (user_input == "left") {
			// TODO: 왼쪽으로 이동하기
			user->x-= 1;


			is_in(user->x,user->y);
			if(inMap==true) {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user->x, user->y);
				checkState(map, user->x, user->y);
				user->DecreaseHP(1);
			}
		}
		else if (user_input == "right") {
			// TODO: 오른쪽으로 이동하기
			user->x += 1;

			is_in(user->x,user->y);
			if(inMap==true) {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user->x, user->y);
				checkState(map, user->x, user->y);
				user->DecreaseHP(1);
			}
		}
		else if (user_input == "map") {
			// TODO: map 보여주기 함수 호출
			displayMap(map, user->x, user->y);
		}
		else if (user_input == "finish") {
			cout << "finish합니다.";
			break;
		}
		else if(user_input=="information"){
			cout<<*user<<endl;
			continue;
		}
		else if(user_input=="attack"){
			user->DoAttack();
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
		//Hp가 0이하로 되었는지 체크
		if(!(CheckUser(user))){
			cout<<"HP가 0이하가 되었습니다. 실패했습니다.";
			return 0;
		}


		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user->x, user->y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 finish합니다." << endl;
			break;
		}

	}
	return 0;
}
//아이템,포션,적 만났을때 함수
void checkState(vector<vector<int>>map, int user_x, int user_y){
	switch(map[user_y][user_x]){
		case 1:
			cout<<"아이템이 있습니다."<<endl;
			user->IncreaseCnt(1);
			break;
		case 2:
			user->DecreaseHP(2);//hp 감소되는부분객체의DecreaseHP 멤버함수호출로진행
			cout<<"적이 있습니다. HP가 2 줄어듭니다."<<endl;;
			break;
		case 3:
			user->IncreaseHP(2);//물약을먹을경우, hp가2 증가하고, 해당증가는객체동작을사용
			cout<<"포션이 있습니다. HP가 2 늘어납니다."<<endl;
			break;

	}
}

// map와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>>map, int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (j==user_x&&i==user_y){
				cout<<"   "<<user->user_name<<"  |";
				continue;
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
		
	}
	
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>>map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}