// 덩치
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v.resize(N);
    for(int i=0; i<N; i++){
        int w, h;
        cin >> w >> h;
        v[i] = {w, h};
    }

    vector<int> order(N);
    for(int i=0; i<v.size(); i++){
        int cnt = 1;
        for(int j=0; j<v.size(); j++){
            if(v[i].first < v[j].first && v[i].second < v[j].second) cnt++;
        }
        order[i] = cnt;
    }

    for(int x : order) cout << x << ' ';

    return 0;
}