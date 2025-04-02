//N-Queen
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool board[15][15];
bool col[15];
int maxSize;
int answer;

void backTracking(int row){
    if(row==maxSize){
        answer++;
        return;
    }

    for(int c=0; c<maxSize; c++){
        if(col[c]) continue;
        
        bool flag = true;
        for(int i=1; i<=row; i++){
            if(c+i<maxSize && board[row-i][c+i]){
                flag = false;
                break;
            }
            if(c-i>=0 && board[row-i][c-i]){
                flag = false;
                break;
            }
        }

        if(flag){
            col[c] = true;
            board[row][c] = true;
            backTracking(row+1);
            col[c] = false;
            board[row][c] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> maxSize;
    backTracking(0);
    cout << answer;

    return 0;
}