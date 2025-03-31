// 트리의 지름
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int diameter, next_start;
vector<vector<pair<int, int>>> adj;
vector<int> dis;
vector<bool> used;

void DFS(int start, int dis){
    int cnt = 0;
    used[start] = true;

    for(auto desc : adj[start]){
        if(used[desc.first]) continue;
        cnt++;
        DFS(desc.first, dis + desc.second);
    }

    if(cnt==0){
        if(diameter < dis){
            diameter = dis;
            next_start = start;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    adj.resize(n+1);
    dis.resize(n+1, 0);
    used.resize(n+1, false);
    
    for(int i=1; i<n; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    next_start = 1;
    while(true){
        dis.clear();
        used.clear();
        dis.resize(n+1, 0);
        used.resize(n+1, false);

        int temp = diameter;
        DFS(next_start, 0);
        if(temp==diameter) break;
    }
    cout << diameter;
    return 0;
}