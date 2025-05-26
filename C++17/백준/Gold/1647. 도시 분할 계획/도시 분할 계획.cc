//도시 분할 계획
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> nodeCount;

int find(int x){
    if(parent[x]==x) return x;

    return parent[x] = find(parent[x]);
}

bool merge(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x==y) return 0;

    if(nodeCount[x]<nodeCount[y]){
        parent[x] = y;
        nodeCount[y] += nodeCount[x];
    } else{
        parent[y] = x;
        nodeCount[x] += nodeCount[y];
    }

    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<tuple<int, int, int>> edges;
    parent.resize(N+1, -1);
    nodeCount.resize(N+1, 1);

    for(int i=1; i<N+1; i++) parent[i] = i; 
    
    while(M--){
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }
    
    sort(edges.begin(), edges.end());
    
    int count = 0, weights = 0;
    for(auto [w, u, v] : edges){
        if(count==N-2) break;
        if(!merge(u, v)) continue;
        
        count++;
        weights += w;
    }
    
    cout << weights;
    return 0;
}