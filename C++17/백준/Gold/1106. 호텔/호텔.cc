//호텔
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int C, N; cin >> C >> N;
    vector<pair<int, int>> cities(N);
    for(auto &[cost, people] : cities){
        cin >> cost >> people;
    }

    int MAX_COST = 100000;
    vector<int> dp(MAX_COST+1, 0);

    for(auto [cost, people] : cities){
        for(int i=cost; i<=MAX_COST; i++){
            dp[i] = max(dp[i], dp[i-cost] + people);
        }
    }

    for(int i=0; i<=MAX_COST; i++){
        if(dp[i]>=C){
            cout << i << '\n';
            break;
        }
    }

    return 0;
}