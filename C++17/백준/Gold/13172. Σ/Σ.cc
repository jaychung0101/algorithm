//Σ
#include <iostream>
using namespace std;

typedef long long ll;

ll MOD = 1000000007;

ll mod_pow(ll base, ll exp) {
    ll result = 1;

    base %= MOD;

    while(exp){
        if(exp & 1){
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M; cin >> M;

    ll answer = 0;
    for(int i=0; i<M; i++){
        ll d, u; cin >> d >> u;
        answer = (answer + u*mod_pow(d, MOD-2) % MOD) % MOD;
    }

    cout << answer;

    return 0;
}