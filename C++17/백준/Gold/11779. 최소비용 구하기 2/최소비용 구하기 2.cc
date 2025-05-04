//최소비용 구하기2
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> dist;
vector<bool> used;
vector<vector<pair<int, int>>> adj;

void dijkstra(int start, int end){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    dist[start] = 0;
    parent[start] = -1;
    q.push({dist[start], start});

    while(!q.empty()){
        int cv = q.top().second; q.pop();

        if(used[cv]) continue;
        if(cv==end) break;
        used[cv] = true;

        for(auto [nw, nv] : adj[cv]){
            if(used[nv]) continue;
            if(dist[nv]>dist[cv]+nw){
                dist[nv] = dist[cv] + nw;
                parent[nv] = cv;
                q.push({dist[nv], nv});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    parent.resize(N+1, 0);
    adj.resize(N+1, vector<pair<int, int>>());
    dist.resize(N+1, INT32_MAX);
    used.resize(N+1, false);
    
    while(M--){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
    }

    int start, end; cin >> start >> end;
    dijkstra(start, end);

    vector<int> answer;
    int currentNode = end;
    while(parent[currentNode]!=-1){
        answer.push_back(currentNode);
        currentNode = parent[currentNode];
    }
    answer.push_back(currentNode);
    reverse(answer.begin(), answer.end());

    cout << dist[end] << '\n';
    cout << answer.size() << '\n';
    for(int node : answer) cout << node << ' ';

    return 0;
}