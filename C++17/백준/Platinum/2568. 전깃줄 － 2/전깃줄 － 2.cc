#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main(){
    int N; cin >> N;
    vector<pii> lines(N);
    for (int i=0; i<N; i++){
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end());

    vector<int> dp;
    vector<int> dpIdx;
    vector<int> preIdx(N, -1);

    for (int i=0; i<N; i++) {
        int val = lines[i].second;
        auto it = lower_bound(dp.begin(), dp.end(), val);
        int idx = it - dp.begin();

        if(it==dp.end()){
            dp.push_back(val);
            dpIdx.push_back(i);
        } else{
            *it = val;
            dpIdx[idx] = i;
        }

        if(idx>0){
            preIdx[i] = dpIdx[idx-1];
        }
    }
    
    vector<int> lis;
    int cur = dpIdx.back();
    while(cur!=-1){
        lis.push_back(cur);
        cur = preIdx[cur];
    }
    
    reverse(lis.begin(), lis.end());
    
    auto it = lis.begin();
    
    cout << N - lis.size() << '\n';
    for(int i=0; i<N; i++){
        if(it!=lis.end() && i==*it){
            it++;
            continue;
        }
        
        cout << lines[i].first << '\n';
    }
    
    return 0;
}