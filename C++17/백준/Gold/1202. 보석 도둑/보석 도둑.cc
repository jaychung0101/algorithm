//보석 도둑
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    vector<pair<int, int>> jewels(N);
    for(auto &[m, v] : jewels) cin >> m >> v;
    
    vector<int> backpacks(K);
    for(auto &w : backpacks) cin >> w;
    
    sort(jewels.begin(), jewels.end());
    sort(backpacks.begin(), backpacks.end());
    
    long long answer = 0;
    int idx = 0;
    priority_queue<int> pq;
    for(int maxWeight : backpacks){
        while(idx<N && jewels[idx].first<=maxWeight){
            pq.push(jewels[idx++].second);
        }

        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
    return 0;
}