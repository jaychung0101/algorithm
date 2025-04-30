//타임머신
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<tuple<int, int, int>> edges;

    while(M--){
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    vector<ll> dist(N+1, INT32_MAX);
    dist[1] = 0;

    bool hasCycle = false;
    for(int i=1; i<=N; i++){
        for(auto [u, v, w] : edges){
            if(dist[u]!=INT32_MAX && dist[v]>dist[u]+w){
                dist[v] = dist[u] + w;
                if(i==N){
                    hasCycle = true;
                    break;
                }
            }
        }
    }

    if(hasCycle){
        cout << -1;
    }
    else{
        for(int i=2; i<=N; i++){
            cout << (dist[i]==INT32_MAX ? -1 : dist[i]) << '\n';
        }
    }

    return 0;
}