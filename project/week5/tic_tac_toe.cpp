#include <iostream>
using namespace std;

int main(){
    const int numCell=3;
    char board[numCell][numCell]{};
    int x,y;//사용자에게 입력받는 x,y 좌표를 저장할 변수
    
    //보드판 초기화
    for(x=0;x<numCell;x++){
        for(y=0;y<numCell;y++){
            board[x][y]=' ';
        }
    }
    int k=0;
    char currentUser='X';
    
    int end=0;

    while(end==0)//end=1;로 종료시킬수 있게함.

    {   //1.누구 차례인지 출력
        switch(k%2){
        case 0:
            cout<<"첫번째 유저(X)의 차례입니다->";
            currentUser='X';
            break;
        case 1:
            cout<<"두번째 유저(0)의 차례입니다->";
            currentUser='0';
            break;
        }
        //2.좌표 입력 받기
        cout<<"(x,y)좌표를 입력하세요:";
        cin>>x>>y;
        //3.입력받은 좌표의 유효성 체크
        if(x>=numCell || y>=numCell){
            cout<<x<<", "<<y<<": ";
            cout<<" x와 y 둘 중 하나가 칸을 벗어납니다."<<endl;
            continue;
        }
        if(board[x][y]!=' '){
            cout<<x<<", "<<y<<": 이미 돌이 차있습니다."<<endl;
            continue;
        }
        // 4.입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y]=currentUser;

        // 5. 현재 보드 판 출력
        for(int i=0;i<numCell;i++){
            cout<<"---|---|---"<<endl;
            for(int j=0;j<numCell;j++){
                cout<<board[i][j];
                if(j==numCell-1){
                    cout<<endl;
                    break;
                }
                
                cout<<"  |";
            }
            
        }
        cout<<"---|---|---"<<endl;
        k++;


        // 6. 빙고시 승자 출력 후 종료
        // 1번유저 가로세로 승리
        for(int i=0;i<3;i++){
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X'){
                cout<<"1번 유저의 승리입니다!";
                end=1;
            }
        }
        for(int i=0;i<3;i++){
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X'){
                cout<<"1번 유저의 승리입니다!";
                end=1;
            }
        }
        
        // 1번유저 대각선 승리
        if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X'){
            cout<<"1번 유저의 승리입니다!";
            end=1;
        }
        if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X'){
            cout<<"1번 유저의 승리입니다!";
            end=1;
        }
        
        //2번유저 가로세로 승리
        for(int i=0;i<3;i++){
            if (board[i][0] == '0' && board[i][1] == '0' && board[i][2] == '0'){
                cout<<"2번 유저의 승리입니다!";
                end=1;
            }
        }
        for(int i=0;i<3;i++){
            if (board[0][i] == '0' && board[1][i] == '0' && board[2][i] == '0'){
                cout<<"2번 유저의 승리입니다!";
                end=1;
            }
        }

        //2번 유저 대각선승리
        if(board[0][0]=='0' && board[1][1]=='0' && board[2][2]=='0'){
            cout<<"2번 유저의 승리입니다!";
            end=1;
        }
        if(board[0][2]=='0' && board[1][1]=='0' && board[2][0]=='0'){
            cout<<"2번 유저의 승리입니다!";
            end=1;
        }
        
        //7. 모든 칸이 찼으면 종료
        //무승부
        int a=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                if(board[i][j]==' ')
                    a++;
                
        }
        if(a==0){
            cout<<"무승부 입니다";
            end=1;
        }

        
        
    }
       
        
   

    return 0;
}