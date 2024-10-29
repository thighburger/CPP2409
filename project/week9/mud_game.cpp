#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 유저 체력
int hp=20;

bool inMap;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);

// 유저의 위치를 저장할 변수(전역변수로이동)
int user_x = 0; // 가로 번호
int user_y = 0; // 세로 번호

// 사용자의 입력을 저장할 변수(전역변수로이동)
	string user_input = "";

//맵벗어났는지 체크함수
void is_in(){
		inMap = checkXY(user_x, mapX, user_y, mapY);
		if (inMap == false) {
			cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
			if(user_input=="up")
				user_y+=1;
			if(user_input=="down")
				user_y-=1;
			if(user_input=="left")
				user_x+=1;
			if(user_input=="right")
				user_x-=1;
			}
}

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0 , 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	

	
	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		
		

		cout << "현재 HP: "<<hp <<"  명령어를 입력하세요 (up,down,left,right,map,finish): ";
		cin >> user_input;

		if (user_input == "up") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			
			is_in();
			if(inMap==true) {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
				hp--;
			}
		}
		else if (user_input == "down") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1;
			is_in();
			if(inMap==true) {
				cout << "위로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
				hp--;
			}
		}

		else if (user_input == "left") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			is_in();
			if(inMap==true) {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				hp--;
			}
		}
		else if (user_input == "right") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			is_in();
			if(inMap==true) {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				hp--;
			}
		}
		else if (user_input == "map") {
			// TODO: map 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "finish") {
			cout << "finish합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
		//Hp가 0이하로 되었는지 체크
		if(hp<=0){
			cout<<"HP가 0이하가 되었습니다. 실패했습니다.";
			return 0;
		}


		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 finish합니다." << endl;
			break;
		}

	}
	return 0;
}
//아이템,포션,적 만났을때 함수
void checkState(int map[][mapX], int user_x, int user_y){
	switch(map[user_y][user_x]){
		case 1:
			cout<<"아이템이 있습니다."<<endl;
			break;
		case 2:
			hp-=2;
			cout<<"적이 있습니다. HP가 2 줄어듭니다."<<endl;;
			break;
		case 3:
			hp+=2;
			cout<<"포션이 있습니다. HP가 2 늘어납니다."<<endl;
			break;

	}
}

// map와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
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
	checkState(map, user_x, user_y);//호출
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
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

