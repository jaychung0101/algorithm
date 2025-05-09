//아기 상어
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int sharkSize = 2, eatCnt = 0, moveTime = 0;
int N, sx, sy;
vector<vector<int>> map;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void printMap(){
    cout << '\n';
    cout << "T=" << moveTime << ", Size=" << sharkSize << ", eatCnt=" << eatCnt << '\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}
int BFS(){
    vector<vector<bool>> used(N, vector<bool>(N, false));
    deque<pair<int, int>> q;
    int tempMoveTime = 0;

    map[sx][sy] = 0;
    used[sx][sy] = true;
    q.emplace_back(sx, sy);
    
    while(!q.empty()){
        deque<pair<int, int>> tempQ;

        tempMoveTime++;
        vector<pair<int, int>> fishes;
        for(auto [cx, cy] : q){
            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx<0 || nx>=N || ny<0 || ny>=N || used[nx][ny] || map[nx][ny]>sharkSize) continue;
                
                used[nx][ny] = true;

                if(map[nx][ny] && map[nx][ny]<sharkSize){
                    fishes.emplace_back(nx, ny);
                }

                tempQ.emplace_back(nx, ny);
            }
        }

        if(!fishes.empty()){
            moveTime += tempMoveTime;

            sort(fishes.begin(), fishes.end());

            sx = fishes[0].first;
            sy = fishes[0].second;
            map[sx][sy] = 9;
            eatCnt++;

            if(eatCnt==sharkSize){
                eatCnt = 0;
                sharkSize++;
            }

            return 1;
        }
        q = tempQ;
    }
    
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    map.resize(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j]==9){
                sx = i;
                sy = j;
            }
        }
    }

    while(BFS());

    cout << moveTime;

    return 0;
}