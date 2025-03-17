// 유기농 배추
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int M, N, K; 

int BFS(vector<vector<bool>> &v, int x, int y){
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<pair<int, int>> q;
    q.push({x, y});
    v[x][y] = false;
    
    while(!q.empty()){
        pair<int, int> current = q.front(); q.pop();
        int cx = current.first;
        int cy = current.second;

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0 || nx>=M || ny<0 || ny>=N) continue;
            if(!v[nx][ny]) continue;
            q.push({nx, ny});
            v[nx][ny] = false;
        }
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

	int T; cin >> T;
    while(T--){
        int res = 0;

        cin >> M >> N >> K;
        vector<vector<bool>> v(M, vector<bool>(N, false));

        while(K--){
            int x, y; cin >> x >> y;
            v[x][y] = true;
        }

        for(int x=0; x<M; x++){
            for(int y=0; y<N; y++){
                if(v[x][y]) res += BFS(v, x, y);
            }
        }

        cout << res << '\n';
    }
}