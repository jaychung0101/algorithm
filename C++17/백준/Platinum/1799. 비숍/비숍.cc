#include <iostream>
#include <vector>
using namespace std;

int N, maxloc, answer = 0;
int board[10][10];
bool rightDown[20];

void backTracking(int sum, int cnt){
    if(maxloc+1-sum+cnt<=answer) return;
    if(sum>maxloc){
        answer = max(answer, cnt);
        return;
    }
    
    // 해당 대각선에 놓지 않음
    backTracking(sum+1, cnt);
    
    for(int i=0; i<=sum; i++){
        int row = i, col = sum-i;
        if(row>=N || col>=N) continue;
        if(!board[row][col] || rightDown[row-col+N-1]) continue;
        
        rightDown[row-col+N-1] = true;
        backTracking(sum+1, cnt+1);
        rightDown[row-col+N-1] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    maxloc = 2*(N-1);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }
    
    backTracking(0, 0);
    
    cout << answer;
    return 0;
}