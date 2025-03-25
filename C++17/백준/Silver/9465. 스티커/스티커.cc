// 스티커
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<vector<int>> dp(2, vector<int>(N, -1));
        vector<vector<int>> v(2, vector<int>(N));

        for(int i=0; i<2; i++){
            for(int j=0; j<N; j++){
                cin >> v[i][j];
            }
        }

        dp[0][0] = v[0][0]; dp[0][1] = v[0][1] + v[1][0];
        dp[1][0] = v[1][0]; dp[1][1] = v[0][0] + v[1][1];

        for(int i=2; i<N; i++){
            dp[0][i] = max(dp[1][i-2], dp[1][i-1]) + v[0][i];
            dp[1][i] = max(dp[0][i-2], dp[0][i-1]) + v[1][i];
        }

        cout << max(dp[0][N-1], dp[1][N-1]) << '\n';
    }
}