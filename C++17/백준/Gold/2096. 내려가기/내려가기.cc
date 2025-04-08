// 내려가기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> dp1(3), dp2(3), next(3);
    for(int &x : dp1) cin >> x;
    dp2 = dp1;

    for(int i=1; i<N; i++){
        for(int &x : next) cin >> x;
        vector<int> temp1 = dp1;
        vector<int> temp2 = dp2;

        dp1[0] = next[0] + max(temp1[0], temp1[1]);
        dp1[1] = next[1] + *max_element(temp1.begin(), temp1.end());
        dp1[2] = next[2] + max(temp1[1], temp1[2]);

        dp2[0] = next[0] + min(temp2[0], temp2[1]);
        dp2[1] = next[1] + *min_element(temp2.begin(), temp2.end());
        dp2[2] = next[2] + min(temp2[1], temp2[2]);
    }
    
    cout << *max_element(dp1.begin(), dp1.end()) << ' ' << *min_element(dp2.begin(), dp2.end());

    return 0;
}