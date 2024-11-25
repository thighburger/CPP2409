#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 사용자 정의 함수들 (이전 코드 유지)
void displayMap(vector<vector<int>> map, int user_x, int user_y);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void checkState(vector<vector<int>> map, int user_x, int user_y);
bool CheckUser(User* user);

string user_input = ""; // 사용자 입력을 저장할 변수 (전역변수로 사용)

// Main 함수
int main() {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    User* user = nullptr;  // User 객체의 포인터 (동적 할당을 위해 사용)
    int turn = 0;  // 턴 변수

    // 직업 선택
    cout << "직업을 선택하세요 (1: Magician, 2: Warrior): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        user = new Magician();
        cout << "마법사로 게임을 시작합니다." << endl;
    }
    else if (choice == 2) {
        user = new Warrior();
        cout << "전사로 게임을 시작합니다." << endl;
    }
    else {
        cout << "잘못된 선택입니다. 게임을 종료합니다." << endl;
        return 0;
    }

    // 게임 시작
    while (true) {
        // 현재 유저의 HP와 상태 출력
        cout << "현재 HP: " << user->GetHP() << endl;
        cout << "명령어를 입력하세요 (up, down, left, right, map, finish, information): ";
        cin >> user_input;

        if (user_input == "up") {
            user->y -= 1;
            cout << "위로 한 칸 올라갑니다." << endl;
            displayMap(map, user->x, user->y);
            checkState(map, user->x, user->y);
        }
        else if (user_input == "down") {
            user->y += 1;
            cout << "아래로 한 칸 내려갑니다." << endl;
            displayMap(map, user->x, user->y);
            checkState(map, user->x, user->y);
        }
        else if (user_input == "left") {
            user->x -= 1;
            cout << "왼쪽으로 한 칸 이동합니다." << endl;
            displayMap(map, user->x, user->y);
            checkState(map, user->x, user->y);
        }
        else if (user_input == "right") {
            user->x += 1;
            cout << "오른쪽으로 한 칸 이동합니다." << endl;
            displayMap(map, user->x, user->y);
            checkState(map, user->x, user->y);
        }
        else if (user_input == "map") {
            displayMap(map, user->x, user->y);
        }
        else if (user_input == "finish") {
            cout << "게임을 종료합니다." << endl;
            break;
        }
        else if (user_input == "information") {
            cout << "현재 HP: " << user->GetHP() << ", 아이템 개수: " << user->ItemCnt() << endl;
            continue;
        }
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        // HP가 0 이하가 되었는지 체크
        if (!CheckUser(user)) {
            cout << "HP가 0 이하가 되어 게임 오버!" << endl;
            break;
        }

        // 목적지에 도달했는지 체크
        bool finish = checkGoal(map, user->x, user->y);
        if (finish) {
            cout << "목적지에 도달했습니다! 축하합니다!" << endl;
            break;
        }
    }

    delete user;  // 동적으로 생성한 객체 메모리 해제
    return 0;
}

// 아이템, 포션, 적 만났을 때 함수
void checkState(vector<vector<int>> map, int user_x, int user_y) {
    switch (map[user_y][user_x]) {
        case 1:
            cout << "아이템이 있습니다." << endl;
            user->IncreaseCnt(1);
            break;
        case 2:
            user->DecreaseHP(2); // HP 감소
            cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
            break;
        case 3:
            user->IncreaseHP(2); // 포션 증가
            cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
            break;
    }
}

// map과 사용자 위치 출력 함수
void displayMap(vector<vector<int>> map, int user_x, int user_y) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (i == user_y && j == user_x) {
                cout << "  U  |"; // 현재 유저 위치 표시
            }
            else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break;
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 유저의 위치가 목적지인지 체크하는 함수
bool check