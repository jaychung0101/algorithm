// 가장 긴 증가하는 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    vector<int> A(N), dp;

    int maxLength = 1;
    for(auto &x : A) cin >> x;
    for(int i=0; i<A.size(); i++){
        auto it = lower_bound(dp.begin(), dp.end(), A[i]);
        if(it==dp.end()) dp.push_back(A[i]);
        else *it = A[i];
    }
    
    cout << dp.size();

    return 0;
}