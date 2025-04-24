//파티
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X; 
vector<vector<pair<int, int>>> map;
vector<int> distX;
int answer = 0, answerV = -1;

void dijkstraX(int X){ 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> used(N+1, false);

    distX[X] = 0;
    pq.push({0, X});

    while(!pq.empty()){
        int cV = pq.top().second; pq.pop();

        if(used[cV]) continue;
        used[cV] = true;

        for(auto n : map[cV]){
            int nW = n.first;
            int nV = n.second;
            if(used[nV]) continue;
            if(distX[cV]+nW<distX[nV]){
                distX[nV] = distX[cV]+nW;
                pq.push({distX[nV], nV});
            }
        }
    }
}

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> used(N+1, false);
    vector<int> dist(N+1, INT32_MAX);

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int cV = pq.top().second; pq.pop();

        if(used[cV]) continue;
        if(cV==X){
            answer = max(answer, dist[X] + distX[start]);
            break;
        }
        used[cV] = true;

        for(auto n : map[cV]){
            int nW = n.first;
            int nV = n.second;
            if(used[nV]) continue;
            if(dist[cV]+nW<dist[nV]){
                dist[nV] = dist[cV]+nW;
                pq.push({dist[nV], nV});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> X;
    map.resize(N+1, vector<pair<int, int>>());
    distX.resize(N+1, INT32_MAX);
    while(M--){
        int u, v, w; cin >> u >> v >> w;
        map[u].push_back({w, v});
    }

    dijkstraX(X);
    for(int i=1; i<=N; i++){
        dijkstra(i);
    }
    cout << answer;
    return 0;
}