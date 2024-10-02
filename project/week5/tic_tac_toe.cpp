#include <iostream>
using namespace std;

const int numCell = 3;
char board[numCell][numCell]{};
int x, y;

void initializeBoard() {
    for (int x = 0; x < numCell; x++) {
        for (int y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }
}

void printBoard() {
    for (int i = 0; i < numCell; i++) {
        cout << "---|---|---" << endl;
        for (int j = 0; j < numCell; j++) {
            cout << board[i][j];
            if (j < numCell - 1) {
                cout << " | ";
            }
        }
        cout << endl;
    }
    cout << "---|---|---" << endl;
}

bool checkWin(char currentUser) {
    // 가로, 세로, 대각선 체크
    for (int i = 0; i < numCell; i++) {
        if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) return true;
        if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) return true;
    }
    if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) return true;
    if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) return true;
    return false;
}

bool checkTie() {
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    initializeBoard();
    int k = 0;
    char currentUser = 'X';

    while (true) {
        cout << "현재 보드 상태:" << endl;
        printBoard();

        if (k % 2 == 0) {
            cout << "첫번째 유저(X)의 차례입니다->";
            currentUser = 'X';
        } else {
            cout << "두번째 유저(O)의 차례입니다->";
            currentUser = 'O';
        }

        cout << "(x,y)좌표를 입력하세요: ";
        cin >> x >> y;

        if (x >= numCell || y >= numCell || x < 0 || y < 0) {
            cout << x << ", " << y << ": x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] != ' ') {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        board[x][y] = currentUser;

        if (checkWin(currentUser)) {
            cout << "현재 보드 상태:" << endl;
            printBoard();
            cout << "유저 " << currentUser << "가 승리했습니다!" << endl;
            break;
        }

        if (checkTie()) {
            cout << "현재 보드 상태:" << endl;
            printBoard();
            cout << "무승부입니다!" << endl;
            break;
        }

        k++;
    }

    return 0;
}
