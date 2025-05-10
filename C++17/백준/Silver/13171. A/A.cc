//A
#include <iostream>
using namespace std;

typedef long long ll;

ll MOD = 1000000007;

ll fast_pow1(ll base, ll exp){
    if(exp==0) return 1;

    ll res = fast_pow1(base, exp/2);
    res *= res;
    res %= MOD;
    if(exp%2){
        res *= base;
        res %= MOD;
    }

    return res;
}

ll fast_pow2(ll base, ll exp){
    ll result = 1;

    base %= MOD;

    while(exp){
        if(exp & 1){
            result *= base;
            result %= MOD; 
        }
        base *= base;
        base %= MOD;
        exp >>= 1;
    }

    return result;
}

int main(){
    ll A, X; cin >> A >> X;
    cout << fast_pow2(A, X);

    return 0;
}