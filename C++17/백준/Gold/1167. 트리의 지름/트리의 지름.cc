//트리의 지름
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V; 
vector<vector<pair<int, int>>> adj;

pair<int, int> dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V+1, INT32_MAX);
    vector<bool> used(V+1, false);

    dist[start] = 0;
    pq.push({-1, start});

    int fallNode;
    while(!pq.empty()){
        int cv = pq.top().second; pq.pop();
        
        if(used[cv]) continue;
        used[cv] = true;
        fallNode = cv;

        for(auto [nw, nv] : adj[cv]){
            if(used[nv]) continue;
            if(dist[nv]>dist[cv]+nw){
                dist[nv] = dist[cv] + nw;
                pq.push({dist[nv], nv});
            }
        }
    }

    return {dist[fallNode], fallNode};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> V;
    adj.resize(V+1, vector<pair<int, int>>());

    for(int i=1; i<=V; i++){
        int u; cin >> u;
        while(true){
            int v; cin >> v;
            if(v==-1) break;
            int w; cin >> w;

            adj[u].emplace_back(w, v);
            adj[v].emplace_back(w, u);
        }
    }

    auto [distance, fallNode] = dijkstra(1);
    auto [diameter, _ ] = dijkstra(fallNode);

    cout << diameter;
    return 0;
}