//음악 프로그램
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
        int x, pre; cin >> x;

        for(int i=0; i<x; i++){
            int y; cin >> y;
            if(i==0){
                pre = y;
                continue;
            }

            adj[pre].push_back(y);
            parents[y]++;
            pre = y;
        }
    }

    queue<int> q;
    for(int i=1; i<N+1; i++){
        if(parents[i]==0){
            q.push(i);
        }
    }

    int count = 0;
    vector<int> answer;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        count++;
        answer.push_back(cur);

        for(int nei : adj[cur]){
            if(--parents[nei]==0){
                q.push(nei);
            }
        }
    }

    if(count==N){
        for(int x : answer) cout << x << '\n';
    } else{
        cout << 0;
    }

    return 0;
}