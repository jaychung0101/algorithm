// 테트로미노
#include <iostream>
#include <vector>
using namespace std;

int answer;
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void T4(vector<vector<int>> &paper, int c, int cx, int cy, int sum){
    if((c==0 || c==1)){
        if(cy+1>=0 && cy+1<M && cy-1>=0 && cy-1<M){
            answer = max(answer, sum+paper[cx][cy+1]+paper[cx][cy-1]);
        }
    }
    if((c==2 || c==3)){
        if(cx+1>=0 && cx+1<N && cx-1>=0 && cx-1<N){
            answer = max(answer, sum+paper[cx+1][cy]+paper[cx-1][cy]);
        }
    }
}

void DFS(vector<vector<int>> &paper, vector<vector<bool>> &used, int cnt, int cx, int cy, int sum, int c){
    sum += paper[cx][cy];

    int ny, nx;
    if(cnt==2) T4(paper, c, cx, cy, sum);
    if(cnt==4){
        answer = max(answer, sum);
        return;
    }

    used[cx][cy] = true;
    for(int i=0; i<4; i++){
        nx = cx + dx[i];
        ny = cy + dy[i];

        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
        if(used[nx][ny]) continue;

        DFS(paper, used, cnt+1, nx, ny, sum, i);
    }
    used[cx][cy] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<vector<int>> paper(N, vector<int>(M));
    vector<vector<bool>> used(N, vector<bool>(M, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> paper[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            DFS(paper, used, 1, i, j, 0, 0);
        }
    }

    cout << answer;

    return 0;
}