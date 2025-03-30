// 최단거리
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dis;
vector<bool> processed;

void dijkstra(int startV){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[startV] = 0;
    pq.push({0, startV});

    while(!pq.empty()){
        int cW = pq.top().first;
        int cV = pq.top().second;
        pq.pop();
        processed[cV] = true;

        for(auto neighbor : adj[cV]){
            int nW = neighbor.first;
            int nV = neighbor.second;
            if(processed[nV]) continue;
            if(dis[cV]+nW < dis[nV]){
                dis[nV] = dis[cV]+nW;
                pq.push({dis[nV], nV});
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int V, E; cin >> V >> E;
    int startV; cin >> startV;
    adj.resize(V+1);
    dis.resize(V+1, INT32_MAX);
    processed.resize(V+1, false);

    while(E--){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    dijkstra(startV);

    for(int i=1; i<=V; i++){
        if(dis[i]==INT32_MAX) cout << "INF";
        else cout << dis[i];
        cout << '\n';
    }

    return 0;
}