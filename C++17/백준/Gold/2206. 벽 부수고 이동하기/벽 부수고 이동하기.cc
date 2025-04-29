//벽 부수고 이동하기
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<char>> map;
int dist[1001][1001][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS(){
    deque<vector<int>> q;

    dist[1][1][0] = 1;
    q.push_back({1, 1, 0});

    while(!q.empty()){
        int cx = q.front()[0];
        int cy = q.front()[1]; 
        int cs = q.front()[2]; q.pop_front();

        if(cx==N && cy==M) return dist[cx][cy][cs];
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx<1 || nx>N || ny<1 || ny>M) continue;

            if(map[nx][ny]=='0' && !dist[nx][ny][cs]){
                dist[nx][ny][cs] = dist[cx][cy][cs] + 1;
                q.push_back({nx, ny, cs});
            } 
            else if(map[nx][ny]=='1' && !cs){
                dist[nx][ny][1] = dist[cx][cy][cs] + 1;
                q.push_back({nx, ny, 1});
            }            
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    map.resize(N+1, vector<char>(M+1));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }

    cout << BFS();

    return 0;
}