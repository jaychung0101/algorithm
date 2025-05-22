//다각형의 면적
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<pair<ll, ll>> v(N+1);

    for(int i=0; i<v.size()-1; i++){
        ll x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    v[N] = v[0];

    ll r1=0, r2=0;
    for(int i=0; i<v.size()-1; i++){
        r1 += v[i].first*v[i+1].second;
        r2 += v[i].second*v[i+1].first;
    }
    
    cout.precision(1);
    cout << fixed;
    cout << abs(r1-r2)/2.0;

    return 0;
}