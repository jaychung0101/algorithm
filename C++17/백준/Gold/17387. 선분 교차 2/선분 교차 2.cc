//선분 교차2
#include <iostream>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int ccw(pii a, pii b, pii c) {
    ll cross = (b.first-a.first)*(c.second-a.second) - (b.second-a.second)*(c.first-a.first);

    if (cross > 0) return 1;
    else if (cross < 0) return -1;
    else return 0;
}

bool isCross(pii a, pii b, pii c, pii d) {
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);

    if (ab==0 && cd==0) {
        if(a>b) swap(a, b);
        if(c>d) swap(c, d);
        return !(b<c || d<a);
    }

    return ab <= 0 && cd <= 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pii A, B, C, D;
    cin >> A.first >> A.second >> B.first >> B.second;
    cin >> C.first >> C.second >> D.first >> D.second;

    cout << isCross(A, B, C, D);

    return 0;
}
