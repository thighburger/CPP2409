#include <iostream>
using namespace std;
int main(){
    const int numCell=3;
    char board[numCell][numCell]{};
    int x,y;
    
    //보드판 초기화
    for(x=0;x<numCell;x++){
        for(y=0;y<numCell;y++){
            board[x][y]=' ';
        }
    }
    int k=0;
    char currentUser='X';

    while(true){
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
        cout<<"(x,y)좌표를 입력하세요:";
        cin>>x>>y;
        if(x>=numCell || y>=numCell){
            cout<<x<<", "<<y<<": ";
            cout<<" x와 y 둘 중 하나가 칸을 벗어납니다."<<endl;
            continue;
        }
        if(board[x][y]!=' '){
            cout<<x<<", "<<y<<": 이미 돌이 차있습니다."<<endl;
            continue;
        }

        board[x][y]=currentUser;
        
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

        //1번유저 승리
        for(int i=0;i<3;i++){
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
                cout<<"1번 유저의 승리입니다!";
                
        }
        for(int i=0;i<3;i++){
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
                cout<<"1번 유저의 승리입니다!";
                
        }
        if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')
            cout<<currentUser<<"1번 유저의 승리입니다!";
        if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')
            cout<<currentUser<<"1번 유저의 승리입니다!";
        
        
        //2번유저 승리
        for(int i=0;i<3;i++){
            if (board[i][0] == '0' && board[i][1] == '0' && board[i][2] == '0')
                cout<<"2번 유저의 승리입니다!";
                
        }
        for(int i=0;i<3;i++){
            if (board[0][i] == '0' && board[1][i] == '0' && board[2][i] == '0')
                cout<<"2번 유저의 승리입니다!";
                
        }
        if(board[0][0]=='0' && board[1][1]=='0' && board[2][2]=='0')
            cout<<currentUser<<"2번 유저의 승리입니다!";
        if(board[0][2]=='0' && board[1][1]=='0' && board[2][0]=='0')
            cout<<currentUser<<"2번 유저의 승리입니다!";

        //무승부
        int a=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                if(board[i][j]=' ')
                    a++;
                
        }
        if(a==0){
            cout<<"무승부 입니다";
            break;
        }

        
        
    }
       
        
   

    return 0;
}
