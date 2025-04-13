//특정한 최단 경로
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, E;
int interDis;
bool flag = true;
vector<vector<pair<int, int>>> adj;

pair<int, int> dijkstra(int u1, int u2){
    pair<int, int> answer;

    vector<bool> used(N+1, false);
    vector<int> dist(N+1, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, u1});
    dist[u1] = 0;

    while(!pq.empty()){
        int cV = pq.top().second; pq.pop();
        
        if(used[cV]) continue;
        used[cV] = true;

        for(auto n : adj[cV]){
            int nW = n.first;
            int nV = n.second;
            if(used[nV]) continue;
            if(dist[cV]+nW<dist[nV]){
                dist[nV] = dist[cV] + nW;
                pq.push({dist[nV], nV});
            }
        }
    }

    answer = {dist[1], dist[N]};
    interDis = dist[u2];

    if(dist[1] == INT32_MAX || dist[N]==INT32_MAX || dist[u1]==INT32_MAX || dist[u2]==INT32_MAX) flag = false;
    
    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> E;
    adj.resize(N+1, vector<pair<int, int>>());
    while(E--){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }    

    int n1, n2; cin >> n1 >> n2;
    pair<int, int> answer1 = dijkstra(n1, n2);
    pair<int, int> answer2 = dijkstra(n2, n1);

    if(!flag) cout << -1;
    else {
        cout << min(answer1.first+answer2.second, answer1.second+answer2.first) + interDis;
    }
    cout << '\n';

    return 0;
}