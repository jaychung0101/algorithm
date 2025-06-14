//줄 세우기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> v(N+1, vector<int>());
    vector<int> parent(N+1, 0);
    queue<int> q;
    
    while(M--){
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        parent[y]++;
    }

    for(int i=1; i<N+1; i++){
        if(parent[i]) continue;

        q.push(i);
    }

    while(!q.empty()){
        int x = q.front(); q.pop();
        cout << x << ' ';

        for(int nei : v[x]){
            parent[nei]--;
            if(parent[nei]==0) q.push(nei);
        }
    }

    return 0;
}