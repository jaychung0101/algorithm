//치즈
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int cheezeCount, N, M;
vector<vector<int>> paper;
deque<pair<int, int>> cheezes;
deque<pair<int, int>> meltedCheezes;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void initBFS(){
    deque<pair<int, int>> q;
    paper[0][0] = 2;
    q.emplace_back(0, 0);

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second; q.pop_front();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx<0 || nx>=N || ny<0 || ny>=M || paper[nx][ny]!=0) continue;

            paper[nx][ny] = 2;
            q.emplace_back(nx, ny);
        }
    }
}

void melting(){
    meltedCheezes.clear();
    deque<pair<int, int>> tempQ;
    for(auto [cx, cy] : cheezes){
        int cnt = 0;
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(paper[nx][ny]==2) cnt++;
        }

        if(cnt>=2){
            cheezeCount--;
            meltedCheezes.emplace_back(cx, cy);
        } else{
            tempQ.emplace_back(cx, cy);
        }
    }

    cheezes = tempQ;
}

void BFS(){
    deque<pair<int, int>> q;

    for(auto [cx, cy] : meltedCheezes){
        paper[cx][cy] = 2;

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(paper[nx][ny]!=0) continue;
            
            paper[nx][ny] = paper[cx][cy];
            q.emplace_back(nx, ny);
        }

        while(!q.empty()){
            int cx = q.front().first;
            int cy = q.front().second; q.pop_front();

            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                if(paper[nx][ny]!=0) continue;
                
                paper[nx][ny] = paper[cx][cy];
                q.emplace_back(nx, ny);
            }
        }
    }
}

void printPaper(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << paper[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    paper.resize(N, vector<int>(M, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> paper[i][j];
            if(paper[i][j]){
                cheezes.emplace_back(i, j);
                cheezeCount++;
            }
        }
    }

    initBFS();
    
    int T = 0;
    while(cheezeCount){
        melting();
        BFS();
        // printPaper();
        T++;
    }

    cout << T;

    return 0;
}