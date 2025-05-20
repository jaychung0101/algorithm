//트리와 쿼리
#include <iostream>
#include <vector>
using namespace std;

int N, R, Q; 
vector<vector<int>> adj;
vector<bool> used;
vector<int> sub;

int DFS(int current){
    used[current] = true;

    for(int n : adj[current]){
        if(used[n]) continue;

        sub[current] += DFS(n);
    }

    return sub[current];
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> R >> Q;
    adj.resize(N+1, vector<int>());
    used.resize(N+1, false);
    sub.resize(N+1, 1);

    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(R);

    while(Q--){
        int q; cin >> q;
        cout << sub[q] << '\n';
    }

    return 0;
}