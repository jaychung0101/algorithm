#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) { // {요청 시간, 소요 시간}
    sort(jobs.begin(), jobs.end());
    map<int, priority_queue<
                pair<int, int>, 
                vector<pair<int, int>>, 
                greater<pair<int, int>>
             >
       > eventQueue;    
    int currentTime = 0, idx = 0, processedJob = 0;
    int answer = 0, maxIdx = jobs.size();
    while(processedJob < maxIdx){
        while(idx<maxIdx && jobs[idx][0]<=currentTime){
            eventQueue[jobs[idx][1]].push({jobs[idx][0], idx});
            idx++;
        }
        
        if(idx<maxIdx && eventQueue.empty()){
            currentTime = jobs[idx][0];
            continue;
        }
        
        auto it = eventQueue.begin();
        int spendTime = it->first;
        int requestTime = it->second.top().first; 
        it->second.pop();

        currentTime += spendTime;
        answer += currentTime - requestTime;

        if(it->second.empty()) eventQueue.erase(it);
        
        processedJob++;
    }
    
    
    return answer/maxIdx;
}