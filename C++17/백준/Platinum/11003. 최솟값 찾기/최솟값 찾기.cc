// 최솟값 찾기
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    deque<pair<int, int>> d;

    int k;
    cin >> k;
    d.push_back(make_pair(0, k));
    cout << d.front().second << ' ';
    for(int i=1; i<n; i++){
        cin >> k;
        pair<int, int> p(i, k);
        

        while(!d.empty() && p.second <= d.back().second)
            d.pop_back();

        d.push_back(p);

        cout << d.front().second << ' ';
        if(i-d.front().first == l-1) d.pop_front();
    }

    return 0;
}