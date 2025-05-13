//가장 긴 증가하는 부분 수열 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> v(N), result;
    for(int &x : v) cin >> x;

    for(int x : v){
        auto it = lower_bound(result.begin(), result.end(), x);
        if(it==result.end()){
            result.push_back(x);
        } else{
            *it = x;
        }
    }

    cout << result.size();

    return 0;
}