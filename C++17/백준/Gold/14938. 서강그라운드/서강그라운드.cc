//서강그라운드
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> item;
vector<int> max_item;
vector<vector<pair<int, int>>> adj;
int n, m, r;

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> used(n+1, false);
    vector<int> dist(n+1, INT32_MAX);
    
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()){
        int cV = pq.top().second; pq.pop();

        if(dist[cV]>m) break;
        used[cV] = true;
        
        for(auto neighbor : adj[cV]){
            int nW = neighbor.first;
            int nV = neighbor.second;
            if(used[nV]) continue;
            if(dist[cV]+nW<dist[nV]) {
                dist[nV] = dist[cV] + nW;   
                pq.push({dist[nV], nV});
            }
        }
    }

    int answer = 0;
    for(int i=1; i<n+1; i++){
        if(dist[i]>m) continue;
        answer += item[i];
    }

    max_item[start] = answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> r;
    
    item.resize(n+1);
    max_item.resize(n+1, -1);
    adj.resize(n+1, vector<pair<int, int>>());
    for(int i=1; i<n+1; i++) cin >> item[i];
    while(r--){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    for(int i=1; i<n+1; i++){
        dijkstra(i);
    }

    sort(max_item.begin(), max_item.end());
    cout << max_item[n];
    
    return 0;
}