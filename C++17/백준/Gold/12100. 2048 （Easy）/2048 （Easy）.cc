#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
int answer, N;

vector<vector<int>> moveDown(vector<vector<int>> &b){
  vector<vector<int>> returnBoard(N, vector<int>(N, 0));

  for(int col=0; col<N; col++){
    int idx = N-1; 
    int last = 0;    

    for(int row=N-1; row>=0; row--){
      if(b[row][col]==0) continue;

      if(last==0){
        last=b[row][col];
      } else {
        if(last==b[row][col]){
          returnBoard[idx][col] = last*2;
          last = 0;
        } else {
          returnBoard[idx][col] = last;
          last = b[row][col];
        }
        
        idx--;
      }
    }

    if(last!=0){
      returnBoard[idx][col] = last;
    }
  }

  return returnBoard;
}

vector<vector<int>> moveUp(vector<vector<int>> &b){
  vector<vector<int>> returnBoard(N, vector<int>(N, 0));

  for(int col=0; col<N; col++){
    int idx = 0; 
    int last = 0;    

    for(int row=0; row<N; row++){
      if(b[row][col]==0) continue;

      if(last==0){
        last=b[row][col];
      } else {
        if(last==b[row][col]){
          returnBoard[idx][col] = last*2;
          last = 0;
        } else {
          returnBoard[idx][col] = last;
          last = b[row][col];
        }
        
        idx++;
      }
    }

    if(last!=0){
      returnBoard[idx][col] = last;
    }
  }

  return returnBoard;
}

vector<vector<int>> moveRight(vector<vector<int>> &b){
  vector<vector<int>> returnBoard(N, vector<int>(N, 0));

  for(int row=0; row<N; row++){
    int idx = N-1; 
    int last = 0;    

    for(int col=N-1; col>=0; col--){
      if(b[row][col]==0) continue;

      if(last==0){
        last=b[row][col];
      } else {
        if(last==b[row][col]){
          returnBoard[row][idx] = last*2;
          last = 0;
        } else {
          returnBoard[row][idx] = last;
          last = b[row][col];
        }
        
        idx--;
      }
    }

    if(last!=0){
      returnBoard[row][idx] = last;
    }
  }

  return returnBoard;
}

vector<vector<int>> moveLeft(vector<vector<int>> &b){
  vector<vector<int>> returnBoard(N, vector<int>(N, 0));

  for(int row=0; row<N; row++){
    int idx = 0; 
    int last = 0;    

    for(int col=0; col<N; col++){
      if(b[row][col]==0) continue;

      if(last==0){
        last=b[row][col];
      } else {
        if(last==b[row][col]){
          returnBoard[row][idx] = last*2;
          last = 0;
        } else {
          returnBoard[row][idx] = last;
          last = b[row][col];
        }
        
        idx++;
      }
    }

    if(last!=0){
      returnBoard[row][idx] = last;
    }
  }

  return returnBoard;
}

void move(vector<vector<int>> &b, int cnt){
  if(cnt==5){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        answer = max(answer, b[i][j]);
      }
    }
    return;
  }

  vector<vector<int>> t;
  bool flag = false;
  
  t = moveUp(b);
  if(t!=b){
    move(t, cnt+1);
    flag = true;
  }

  t = moveDown(b);
  if(t!=b){
    move(t, cnt+1);
    flag = true;
  }

  t = moveLeft(b);
  if(t!=b){
    move(t, cnt+1);
    flag = true;
  }

  t = moveRight(b);
  if(t!=b){
    move(t, cnt+1);
    flag = true;
  }
  
  if(!flag){
    move(b, 5);
  }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    board.resize(N, vector<int>(N));
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        cin >> board[i][j];
      }
    }
    
    move(board, 0);
    cout << answer;
}