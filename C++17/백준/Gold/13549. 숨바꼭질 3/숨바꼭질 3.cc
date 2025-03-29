// 숨바꼭질 3
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, answer;
vector<int> disTime;

int BFS(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    disTime[start] = 0;
    pq.push({disTime[start], start});

    while(!pq.empty()){
        int currentTime = pq.top().first; 
        int currentLoc = pq.top().second;
        pq.pop();

        int dx[3] = {currentLoc, -1, 1};

        for(int i=0; i<3; i++){
            int nx = currentLoc + dx[i];
            if(nx<0 || nx >= disTime.size()) continue;
            if(disTime[nx]!=-1) continue;
            disTime[nx] = (i==0 ? disTime[currentLoc] : disTime[currentLoc] + 1);
            if(nx==K) return disTime[nx];
            pq.push({disTime[nx], nx});    
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    disTime.resize(2*K+1, -1);
    answer = (N>=K ? N-K : BFS(N));
    cout << answer;
    return 0;
}