// 플로이드
#include <iostream>
#include <vector>
using namespace std;

int n, m;

void print(vector<vector<int>> &answer){
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cout << (answer[i][j]==INT32_MAX ? 0 : answer[i][j]) << ' ';
        }
        cout << '\n';
    }
}

void floyd(vector<vector<int>> &adj, vector<vector<int>> &answer){
    for(int i=1; i<n+1; i++){ // init floyd
        for(int j=1; j<n+1; j++){
            if(i==j){
                answer[i][j] = 0;
                continue;
            }
            answer[i][j] = adj[i][j];
        }
    }

    for(int k=1; k<n+1; k++){
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if (answer[i][k] != INT32_MAX && answer[k][j] != INT32_MAX)
                    answer[i][j] = min(answer[i][j], answer[i][k] + answer[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(n+1, INT32_MAX));
    vector<vector<int>> answer(n+1, vector<int>(n+1, INT32_MAX));
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }

    floyd(adj, answer);
    print(answer);
}