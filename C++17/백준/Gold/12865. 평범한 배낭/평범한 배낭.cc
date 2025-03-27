// 평범한 배낭
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    vector<pair<int, int>> product(N);
    for(int i=0; i<N; i++){
        int w, v; cin >> w >> v;
        product[i] = {w, v};
    }

    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
    for(int i=1; i<K+1; i++){
        for(int j=1; j<N+1; j++){
            pair<int, int> c = product[j-1];
            dp[i][j] = (i-c.first>-1 ? max(dp[i][j-1], dp[i-c.first][j-1] + c.second) : dp[i][j-1]);
        }
    }

    cout << dp[K][N];
    return 0;
}