//트리의 부모 찾기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void search(vector<vector<int>> &adj, vector<int> &parent, vector<bool> &state){
    queue<int> q;
    q.push(1);
    state[1] = true;

    while(!q.empty()){
        int current = q.front(); q.pop();
        state[current] = true;
        for(int neighbor : adj[current]){
            if(state[neighbor]) continue;
            state[neighbor] = true;
            parent[neighbor] = current;
            q.push(neighbor);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<vector<int>> adj(N+1, vector<int>());
    vector<int> parent(N+1, -1);
    vector<bool> state(N+1, false);
    for(int i=0; i<N-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    search(adj, parent, state);
    for(int i=2; i<N+1; i++) cout << parent[i] << '\n';

    return 0;
}