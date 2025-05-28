//스도쿠
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> m(9, vector<int>(9));
vector<vector<int>> answer;
bool row[9][10]; //[각 행마다][어떤 숫자가 존재하는지]
bool column[9][10]; //[각 열마다][어떤 숫자가 존재하는지]
bool local[9][10]; //[각 칸마다][어떤 숫자가 존재하는지]


int localLoc(int r, int c){
    /*
        0   1   2
        3   4   5
        6   7   8
    */
    return (r/3)*3 + (c/3);
}

void backTraking(int r, int c){
    if(answer.size()>0) return;
    if(r==9){
        answer = m;
        return;
    }

    if(m[r][c]){
        if(c==8){
            backTraking(r+1, 0);
        } else{
            backTraking(r, c+1);
        }
        return;
    }

    for(int i=1; i<=9; i++){
        if(row[r][i] || column[c][i] || local[localLoc(r, c)][i]) continue;

        m[r][c] = i;
        row[r][i] = column[c][i] = local[localLoc(r, c)][i] = 1;

        if(c==8){
            backTraking(r+1, 0);
        } else{
            backTraking(r, c+1);
        }

        m[r][c] = 0;
        row[r][i] = column[c][i] = local[localLoc(r, c)][i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(row, 0, sizeof(row));
    memset(column, 0, sizeof(column));
    memset(local, 0, sizeof(local));

    for(int r=0; r<9; r++){
        for(int c=0; c<9; c++){
            char x; cin >> x;
            int y = int(x-'0');
            m[r][c] = y;
            if(y){
                row[r][y] = 1;
                column[c][y] = 1;
                local[localLoc(r, c)][y] = 1;
            }
        }
    }

    backTraking(0, 0);

    for(int r=0; r<9; r++){
        for(int c=0; c<9; c++){
            cout << answer[r][c];
        }
        cout << '\n';
    }

    return 0;
}