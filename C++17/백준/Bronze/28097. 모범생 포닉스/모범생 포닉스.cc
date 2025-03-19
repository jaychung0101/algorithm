// 모범생 포닉스
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int res = 8*(N-1);
    while(N--){
        int t; cin >> t;
        res += t;
    }
    cout << res/24 << ' ' << res%24;
    return 0;
}