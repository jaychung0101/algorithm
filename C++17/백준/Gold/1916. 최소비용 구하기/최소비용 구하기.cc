// 최소비용 구하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> used;
vector<int> dist;

void dijkstra(vector<vector<pair<int,int>>> &adj, int dep, int dest){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({-1, dep});
    dist[dep] = 0;

    while(!pq.empty()){
        int cV = pq.top().second; pq.pop();
        if(used[cV]) continue;
        if(cV==dest) return;
        used[cV] = true;

        for(auto n : adj[cV]){
            int nW = n.first;
            int nV = n.second;
            if(used[nV]) continue;
            if(dist[cV]+nW < dist[nV]){
                dist[nV] = dist[cV] + nW;
                pq.push({dist[nV], nV});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<pair<int,int>>> adj(N+1, vector<pair<int, int>>());
    used.resize(N+1, 0);
    dist.resize(N+1, INT32_MAX);
    while(M--){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    int dep, dest; cin >> dep >> dest;
    dijkstra(adj, dep, dest);
    cout << dist[dest];

    return 0;
}