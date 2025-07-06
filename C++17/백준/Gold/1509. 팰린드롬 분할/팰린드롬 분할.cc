//팰린드롬 분할
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    int maxIdx = s.size();

    vector<vector<bool>> dp(maxIdx, vector<bool>(maxIdx, false));

    for(int i=0; i<maxIdx; i++) dp[i][i] = true;
    for(int i=0; i<maxIdx-1; i++){
        dp[i][i+1] = (s[i]==s[i+1] ? true : false);
    }

    for(int unit=2; unit<maxIdx; unit++){
        for(int i=0; i<maxIdx; i++){
            if(i+unit>=maxIdx) break;
            dp[i][i+unit] = (dp[i+1][i+unit-1] && s[i]==s[i+unit]);
        }
    }

    vector<int> answer(maxIdx+1, INT32_MAX);
    answer[0] = 0;

    for(int i=0; i<maxIdx; i++){
        for(int j=0; j<=i; j++){
            if(dp[j][i]){
                answer[i+1] = min(answer[i+1], answer[j]+1);
            }
        }
    }

    cout << answer[maxIdx];

    return 0;
}