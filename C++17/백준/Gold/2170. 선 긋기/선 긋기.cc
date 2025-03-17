// 선긋기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;

int main() {
	fast_io
	
    int N;
    cin >> N;
    vector<pair<ll, ll>> a(N);

    ll L, R;
    for(int i=0; i<N; i++) {
        cin >> L >> R;
        a[i] = make_pair(L, R);
    }

    sort(a.begin(), a.end());
    L=a[0].first; R=a[0].second;

    ll sum = 0;   
    for(int i=1; i<N; i++) {
        if(a[i].first<R && a[i].second>R) R=a[i].second;
        else if(a[i].first>=R){
            sum += R-L;
            L=a[i].first; R=a[i].second;
        }
    }
    sum += R-L;

    cout << sum;

    return 0;
}