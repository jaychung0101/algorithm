#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
#include <set>
#include <map>
using namespace std;
using pii = pair<int, int>;

char building[102][102];
bool visited[102][102];
set<char> initKeys;
set<char> keys;
map<char, vector<pii>> doors;
int h, w, answer; 

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init(){
    answer = 0;
    cin >> h >> w;

    for(int i=0; i<h+2; i++){
        for(int j=0; j<w+2; j++){
            building[i][j] = '.';
        }
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> building[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));
    
    string s; cin >> s;
    
    initKeys.clear();
    if(s!="0") {
        for(char key : s){
            initKeys.insert(key);
        }
    }
    
    keys = initKeys;

    doors.clear();
}

void pringMap(){
    for(int i=0; i<=h+1; i++){
        for(int j=0; j<=w+1; j++){
            cout << visited[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void BFS(int x, int y){
    deque<pii> next;
    next.emplace_back(x, y);
    visited[x][y] = true;
    
    while(!next.empty()){
        // pringMap();
        auto [cx, cy] = next.front(); next.pop_front();
        char &cur = building[cx][cy];
        
        if(cur=='$'){
            answer++;
            cur = '.';
        } else if ('a' <= cur && cur <= 'z') {
            if (!keys.count(cur)) {
                keys.insert(cur);

                for(auto [tx, ty] : doors[toupper(cur)]) {
                    visited[tx][ty] = true;
                    next.emplace_back(tx, ty);
                }
                doors[toupper(cur)].clear();
            }
            cur = '.';
        } else if('A'<=cur && cur<='Z'){
            if(!keys.count(tolower(cur))){
                doors[cur].emplace_back(cx, cy);
                continue;
            }
            cur = '.';
        }
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx<0 || nx>=h+2 || ny<0 || ny>=w+2) continue;
            if(visited[nx][ny] || building[nx][ny]=='*') continue;
            
            visited[nx][ny] = true;
            next.emplace_back(nx, ny);
        }
    }
}

int main() {
    int T; cin >> T;
    while(T--){
        init();
        BFS(0, 0);
        cout << answer << '\n';
    }
    return 0;
}