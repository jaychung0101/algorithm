//문명
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int N, K, mergeCount;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> parent;
vector<vector<pair<int, int>>> map;
queue<pair<int, int>> q;

void showMap(int T){
    cout << "T=" << T << '\n';
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            cout << map[i][j].first;
        }
        cout << '\n';
    }
    cout << '\n';
}

int find(int x){
    if(parent[x]==x){
        return x;
    }

    parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int p1, int p2){
    parent[p2] = p1;
    mergeCount++;
}

int BFS(){
    int T = 0;
    while(++T){
        queue<pair<int, int>> tempQ;
        while(!q.empty()){
            int cx = q.front().first; 
            int cy = q.front().second; q.pop();

            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx<1 || nx>N || ny<1 || ny>N) continue;
                if(map[nx][ny].first!=0){
                    int p1 = find(map[cx][cy].first);
                    int p2 = find(map[nx][ny].first);
                    if(p1!=p2){
                        merge(p1, p2);
                        if(mergeCount==K-1){
                            if(map[cx][cy].second==map[nx][ny].second) return T-1;
                            else return T;
                        }
                    }
                    continue;
                }
                map[nx][ny] = {map[cx][cy].first, T};
                tempQ.push({nx, ny});
            }
        }
        q=tempQ;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    map.resize(N+1, vector<pair<int, int>>(N+1, {0, 0}));
    parent.resize(K+1);

    for(int i=1; i<=K; i++){
        int x, y; cin >> x >> y;
        parent[i] = i;
        map[x][y].first = i;

        for(int j=0; j<4; j++){
            int nx = x+dx[j];
            int ny = y+dy[j];
            if(nx<1 || nx>N || ny<1 || ny>N) continue;
            if(map[nx][ny].first){
                int p1 = find(map[x][y].first);
                int p2 = find(map[nx][ny].first);
                if(p1!=p2){
                    merge(p1, p2);
                }
            }
        }
        q.push({x, y});
    }

    cout << (mergeCount==K-1 ? 0 : BFS());
    return 0;
}