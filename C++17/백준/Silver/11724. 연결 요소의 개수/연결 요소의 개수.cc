// 연결 요소의 개수
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, res; 

void BFS(vector<vector<int>> &adj, vector<bool> &state){
    for(int i=1; i<N+1; i++){
        if(state[i]) continue;
        queue<int> q;
        q.push(i);
        state[i] = true;

        while(!q.empty()){
            int current = q.front(); q.pop();
            for(auto neighbor : adj[current]){
                if(state[neighbor]) continue;
                state[neighbor] = true;
                q.push(neighbor);
            }
        }
        res++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<vector<int>> adj(N+1);
    vector<bool> state(N+1, false);
    while(M--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    BFS(adj, state);
    cout << res;
    
    return 0;
}