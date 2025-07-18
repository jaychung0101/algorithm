// 구슬 탈출 2
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
using namespace std;
using pii = pair<int, int>;

int N, M;
pii hole;
vector<vector<char>> b; 

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<pii, int> moveBall(pii ball, int dr, int dc) {
    int row = ball.first, col = ball.second;
    int distance = 0;

    while(true) {
        int nr = row + dr;
        int nc = col + dc;

        if(nr<0 || nr>=N || nc<0 || nc>=M) break;
        char next = b[nr][nc];

        if(next=='#') break;
        if(next=='O') return {{nr, nc}, distance+1};

        row = nr;
        col = nc;
        distance++;
    }

    return {{row, col}, distance};
}

int bfs(pii red, pii blue) {
    queue<tuple<pii, pii, int>> q;
    set<pair<pii, pii>> visited;

    q.push({red, blue, 1});
    visited.insert({red, blue});

    while (!q.empty()) {
        auto [r, b, cnt] = q.front(); q.pop();
        if (cnt > 10) break;

        for (int d = 0; d < 4; d++) {
            auto redInf = moveBall(r, dx[d], dy[d]);
            auto blueInf = moveBall(b, dx[d], dy[d]);

            if (blueInf.first == hole) continue;
            if (redInf.first == hole) return cnt;

            if (redInf.first == blueInf.first) {
                if (redInf.second > blueInf.second) {
                    redInf.first.first -= dx[d];
                    redInf.first.second -= dy[d];
                } else {
                    blueInf.first.first -= dx[d];
                    blueInf.first.second -= dy[d];
                }
            }

            pair<pii, pii> newState = {redInf.first, blueInf.first};
            if (!visited.count(newState)) {
                visited.insert(newState);
                q.push({redInf.first, blueInf.first, cnt + 1});
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    b.resize(N, vector<char>(M, '.'));

    pii red, blue;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c; cin >> c;

            if(c=='R'){
                red = make_pair(i, j);
            } else if(c=='B'){
                blue = make_pair(i, j);
            } else if(c=='O'){
                hole = make_pair(i, j);
            }
            
            if(c=='#' || c=='O') b[i][j] = c;
        }
    }

    cout << bfs(red, blue) << '\n';
}