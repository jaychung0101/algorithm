#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, priority_queue<pair<int, int>>> map; // key: 장르 / value:{재생 횟수, 고유 번호}
    unordered_map<string, int> playCnt;
    
    for(int idx=0; idx<genres.size(); idx++){
        map[genres[idx]].push({plays[idx], idx});
        if(!playCnt.count(genres[idx])) playCnt[genres[idx]] = plays[idx];
        else playCnt[genres[idx]] += plays[idx];
    }
    
    vector<pair<int, string>> v;
    for(auto comp : playCnt) v.push_back({comp.second, comp.first});
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for(auto comp : v){
        int cnt = 0;
        vector<int> temp;
        while(!map[comp.second].empty() && cnt<2){
            int play = map[comp.second].top().first;
            int idx = map[comp.second].top().second;
            map[comp.second].pop();
            
            temp.push_back(idx);
            if(play!=map[comp.second].top().first){
                for(int i=temp.size()-1; i>=0; i--){
                    answer.push_back(temp[i]);
                    cnt++;
                    if(cnt==2) break;
                }
                temp.clear();
            }
        }
        if(cnt<2 && !temp.empty()) answer.push_back(temp[0]);
    }
    return answer;
}