//줄 세우기
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> v(N+1, vector<int>());
    vector<int> parent(N+1, 0);
    vector<bool> used(N+1, false);

    while(M--){
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        parent[y]++;
    }

    int count = 0;
    while(count<N){
        for(int i=1; i<N+1; i++){
            if(used[i]) continue;

            if(parent[i]==0){
                cout << i << ' ';
                used[i] = true;
                for(int nei : v[i]){
                    parent[nei]--;
                }
                count++;
            }
        }
    }

    return 0;
}