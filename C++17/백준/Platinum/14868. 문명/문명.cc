//문명
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, K, mergeCount;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> parent;
vector<vector<pair<int, int>>> map;
deque<pair<int, int>> q;

void showMap(int T){
    cout << "T=" << T << ", mergeCnt=" << mergeCount << '\n';
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            cout << map[i][j].first << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int find(int x){
    if(parent[x]==x){
        return x;
    }

    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    parent[y] = x;
    mergeCount++;
}

int BFS(){
    int T = 0;
    while(mergeCount<K-1){
        deque<pair<int, int>> tempQ;
        for(pair<int, int> c : q){
            int cx = c.first; 
            int cy = c.second;

            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx<1 || nx>N || ny<1 || ny>N || map[nx][ny].first!=0) continue;

                map[nx][ny] = {map[cx][cy].first, T};
                tempQ.emplace_back(nx, ny);
            }
        }

        for(pair<int, int> c : tempQ){
            int cx = c.first; 
            int cy = c.second;

            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx<1 || nx>N || ny<1 || ny>N || map[nx][ny].first==0) continue;
                
                merge(map[cx][cy].first, map[nx][ny].first);
            }
        }

        T++;
        q=tempQ;
    }

    return T;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    map.resize(N+1, vector<pair<int, int>>(N+1, {0, 0}));
    parent.resize(K+1);

    for(int i=1; i<=K; i++){
        int cx, cy; cin >> cx >> cy;
        parent[i] = i;
        map[cx][cy].first = i;
        q.emplace_back(cx, cy); 
    }

    for(auto c : q){
        int cx = c.first;
        int cy = c.second;
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx<1 || nx>N || ny<1 || ny>N || map[nx][ny].first==0) continue;

            merge(map[cx][cy].first, map[nx][ny].first);
        }
    }

    cout << BFS();
    return 0;
}