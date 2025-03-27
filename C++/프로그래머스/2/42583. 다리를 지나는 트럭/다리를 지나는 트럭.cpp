#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> q;
    int time = 0;
    int idx = 0, currentWeight = 0;
    while(true){
        time++;
        if(!q.empty() && time-q.front().first==bridge_length){
            currentWeight-=q.front().second;
            q.pop();
        }
        
        if(q.size()<bridge_length && currentWeight+truck_weights[idx]<=weight){
            currentWeight+=truck_weights[idx];
            q.push({time, truck_weights[idx]});
            if(++idx==truck_weights.size()) break;
        }
    }
    
    time += bridge_length;
    return time;
}