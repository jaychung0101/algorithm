//웜홀
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC; cin >> TC;
    while(TC--){
        int N, roadNum, wormholeNum; cin >> N >> roadNum >> wormholeNum;
        
        vector<tuple<int, int, int>> edges;

        while(roadNum--){
            int u, v, w; cin >> u >> v >> w;
            edges.emplace_back(u, v, w);
            edges.emplace_back(v, u, w);
        }

        while(wormholeNum--){
            int u, v, w; cin >> u >> v >> w;
            edges.emplace_back(u, v, -w);
        }

        for(int i=1; i<=N; i++){
            edges.emplace_back(0, i, 0);
        }

        vector<int> dist(N+1, INT32_MAX);
        dist[0] = 0;

        bool hasCycle = false;
        for(int i=0; i<=N; i++){
            for(auto [u, v, w] : edges){
                if(dist[u]!=INT32_MAX && dist[v]>dist[u]+w){
                    dist[v] = dist[u] + w;
                    if(i==N) hasCycle = true;
                }
            }
        }

        cout << (hasCycle ? "YES" : "NO") << '\n';
    }

    return 0;
}