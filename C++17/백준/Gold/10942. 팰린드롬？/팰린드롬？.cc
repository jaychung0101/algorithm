//팰린드롬?
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> v(N+1);
    for(int i=1; i<N+1; i++) cin >> v[i];

    vector<vector<bool>> dp(N+1, vector<bool>(N+1, 0));
    for(int i=1; i<N+1; i++){
        dp[i][i] = true;
    }

    for(int i=1; i<N; i++){
        if(v[i]==v[i+1]) dp[i][i+1] = true;
    }

    for(int len=3; len<N+1; len++){
        for(int i=1; i<=N-len+1; i++){
            int j = i + len - 1;
            if(v[i]==v[j] && dp[i+1][j-1])
                dp[i][j] = true;
        }
    }

    int M; cin >> M;
    while(M--){
        int S, E; cin >> S >> E;
        cout << dp[S][E] << '\n';
    }

    return 0;
}