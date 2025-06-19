//피리 부는 사나이
#include <iostream>
#include <vector>
using namespace std;

bool newCycle;
int answer;
vector<vector<char>> map;
vector<vector<bool>> visited;
vector<vector<bool>> finished;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int direction(char c){
    if(c=='D'){
        return 0;
    } else if(c=='U'){
        return 1;
    } else if(c=='R'){
        return 2;
    } else{
        return 3;
    }
}

void DFS(int r, int l){
    if(!visited[r][l]){    
        visited[r][l] = true;
        int d = direction(map[r][l]);
        DFS(r+dx[d], l+dy[d]);
    } else if(finished[r][l]){
        newCycle = 0;
        return;
    }

    finished[r][l] = true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, M; cin >> N >> M;
    map = vector<vector<char>>(N, vector<char>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    finished = vector<vector<bool>>(N, vector<bool>(M, false));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(finished[i][j]) continue;
            newCycle = 1;
            DFS(i, j);
            if(newCycle) {
                answer++;
            }
        }
    }

    cout << answer;
    return 0;
}