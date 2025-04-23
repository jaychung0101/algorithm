//미세먼지 안녕!
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, T;
vector<vector<int>> map;
queue<pair<int, int>> q;
pair<int, int> top = {-1, -1}, bottom = {-1, -1};

void spreadOut(){
    vector<vector<int>> temp(R, vector<int>(C, 0));
    queue<pair<int, int>> q_temp;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while(!q.empty()){
        int cx = q.front().first; 
        int cy = q.front().second;
        q.pop();

        int cnt = 0;
        bool move[4] = {0, 0, 0, 0};
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx<0 || nx>=R || ny<0 || ny>=C || make_pair(nx, ny)==top || make_pair(nx, ny)==bottom) continue;
            move[i] = true;
            cnt++;
        }

        int spreadAmount = map[cx][cy]/5;
        temp[cx][cy] -= spreadAmount*cnt;
        for(int i=0; i<4; i++){
            if(!move[i]) continue;

            int nx = cx + dx[i];
            int ny = cy + dy[i];
            temp[nx][ny] += spreadAmount;
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            map[i][j] += temp[i][j];
        }
    }
}

void cleaning(){
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    int cx = top.first, cy = top.second;
    int temp1 = 0, temp2;
    for(int i=0; i<4; i++){
        while(true){
            cx += dx[i];
            cy += dy[i];

            if(cx<0 || cy<0 || cy==C) break;
            if(make_pair(cx, cy)==top) break;

            temp2 = map[cx][cy];
            map[cx][cy] = temp1;
            temp1 = temp2;
        }

        cx -= dx[i];
        cy -= dy[i];
    }

    dx[0] = 0, dx[1] = 1, dx[2] = 0, dx[3] = -1;
    dy[0] = 1, dy[1] = 0, dy[2] = -1, dy[3] = 0;

    cx = bottom.first, cy = bottom.second;
    temp1 = 0;
    for(int i=0; i<4; i++){
        while(true){
            cx += dx[i];
            cy += dy[i];

            if(cx==R || cy<0 || cy==C) break;
            if(make_pair(cx, cy)==bottom) break;

            temp2 = map[cx][cy];
            map[cx][cy] = temp1;
            temp1 = temp2;
        }

        cx -= dx[i];
        cy -= dy[i];
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j]>0) q.push({i, j});
        }
    }
}

int totalAmount(){
    int total = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j]>0){
                total += map[i][j];
            }
        }
    }

    return total;
}

void showMap(){
    cout << '\n';
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> T;
    map.resize(R, vector<int>(C));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j];
            if(map[i][j]>0) q.push({i, j});
            if(map[i][j]<0){
                if(top.first==-1) top = {i, j};
                else bottom = {i, j};
            }
        }
    }
    
    for(int i=0; i<T; i++){
        spreadOut();
        cleaning();

        // cout << "\nT=" << i+1;
        // showMap();
    }

    cout << totalAmount() << '\n';
    return 0;
}