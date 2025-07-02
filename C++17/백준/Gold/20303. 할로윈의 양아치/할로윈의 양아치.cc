//할로윈의 양아치
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector<int> candies;
vector<vector<int>> adj;
vector<bool> used;
vector<pii> units;
vector<int> maxCandies;

void BFS(int start){
    queue<int> q;
    q.push(start);
    used[start] = true;
    
    int childCnt = 0, candyCnt = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        childCnt++;
        candyCnt += candies[cur];

        for(int nei : adj[cur]){
            if(used[nei]) continue;
            used[nei] = true;
            q.push(nei);
        }
    }

    units.emplace_back(childCnt, candyCnt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, K; cin >> N >> M >> K;
    
    K = min(K, 3000);
    candies.resize(N+1);
    adj.resize(N+1, vector<int>());
    used.resize(N+1, false);
    maxCandies.resize(K, 0);

    for(int i=1; i<N+1; i++) cin >> candies[i];
    while(M--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<N+1; i++){
        if(used[i]) continue;
        BFS(i);
    }

    sort(units.begin(), units.end());
    
    for(auto [w, v] : units){
        for(int i=maxCandies.size()-1; i>=0; i--){
            if(i-w < 0) continue;
            maxCandies[i] = max(maxCandies[i-w]+v, maxCandies[i]);
        }
    }

    cout << maxCandies[K-1];
    return 0;
}