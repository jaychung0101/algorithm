// 집에선 안돼잉
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long N, M, T, S; cin >> N >> M >> T >> S;

    long long zip = N, dok = M;

    if(N%8==0) zip += (N/8-1)*S;
    else zip += (N/8)*S;

    if(M%8==0) dok += (M/8-1)*(2*T+S) + T;
    else dok += (M/8)*(2*T+S) + T;

    cout << (zip < dok ? "Zip" : "Dok") << '\n';
    cout << min(zip, dok);

    return 0;
}