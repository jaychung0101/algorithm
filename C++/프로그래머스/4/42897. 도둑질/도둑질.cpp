#include <vector>
#include <algorithm>

using namespace std;

int dp[1000001][2]; // 집 / 첫번째 집 털었는지

int solution(vector<int> money) {
    dp[0][1] = money[0]; dp[0][0] = 0;
    dp[1][1] = 0; dp[1][0] = money[1];
    dp[2][0] = max(money[1], money[2]); dp[2][1] = dp[0][1] + money[2];
    
    int maxIdx = money.size()-1;
    for(int i=3; i<maxIdx; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-2][0] + money[i], dp[i-3][0] + money[i]});
        dp[i][1] = max({dp[i-1][1], dp[i-2][1] + money[i], dp[i-3][1] + money[i]});
    }
    
    dp[maxIdx][0] = max({dp[maxIdx-1][0], dp[maxIdx-2][0] + money[maxIdx], dp[maxIdx-3][0] + money[maxIdx]});
    dp[maxIdx][1] = max({dp[maxIdx-1][1], dp[maxIdx-2][1]});
    int answer = max({dp[maxIdx][0], dp[maxIdx][1]});
    return answer;
}