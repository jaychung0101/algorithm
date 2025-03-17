// 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    vector<pair<int, int>> v(N);
    
    int x, y; 
    for(int i=0; i<N; i++){
        cin >> x >> y;
        v[i] = {x, y};
    }

    sort(v.begin(), v.end());

    int res = 1;
    int last = v[0].second;
    for(int i=1; i<N; i++){
        if(v[i].first >= last){
            res++;
            last = v[i].second;
        }
        if(v[i].second < last){
            last = v[i].second;
        }
    }

    cout << res;

    return 0;
}