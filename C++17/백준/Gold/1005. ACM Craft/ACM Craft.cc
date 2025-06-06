//ACM Craft
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        vector<vector<int>> adj(N+1);
        vector<int> cost(N+1), indegree(N+1, 0);
        for(int i=1; i<N+1; i++) cin >> cost[i];

        while(K--){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            indegree[y]++;
        }

        int W; cin >> W;
        vector<int> dp(N+1, 0);
        queue<int> q;

        for(int i=1; i<N+1; i++){
            if(!indegree[i]){
                q.push(i);
                dp[i] = cost[i];
            }
        }

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int next : adj[cur]){
                dp[next] = max(dp[next], dp[cur] + cost[next]);
                if(!--indegree[next]) q.push(next);
            }
        }

        cout << dp[W] << '\n';
    }

    return 0;
}