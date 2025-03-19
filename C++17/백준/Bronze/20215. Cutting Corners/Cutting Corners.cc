// Cutting Corners
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int w, h; cin >> w >> h;

    cout << fixed;
    cout.precision(7);

    cout << w+h - sqrt(w*w+h*h);
    return 0;
}