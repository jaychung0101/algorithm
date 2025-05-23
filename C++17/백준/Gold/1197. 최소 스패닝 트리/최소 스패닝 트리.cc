//최소 스패닝 트리
#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> adj;
unordered_set<int> s;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int V, E; cin >> V >> E;
    adj.resize(V+1, vector<pair<int, int>>());
    while(E--){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    s.insert(1);
    for(auto p : adj[1]) pq.push(p);

    int answer = 0;
    while(s.size()<V){
        while(!pq.empty() && s.count(pq.top().second)) pq.pop();
        
        int nw = pq.top().first;
        int nv = pq.top().second;

        answer += nw;
        s.insert(nv);

        for(auto p : adj[nv]){
           if(!s.count(p.second)) pq.push(p);
        }
    }

    cout << answer;

    return 0;
}