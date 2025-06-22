//문제집
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N+1);
    vector<int> parents(N+1, 0);
    while(M--){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        parents[y]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1; i<N+1; i++){
        if(!parents[i]){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int cur = pq.top(); pq.pop();
        cout << cur << ' ';
        for(int next : adj[cur]){
            if(--parents[next]==0){
                pq.push(next);
            }
        }
    }

    return 0;
}   