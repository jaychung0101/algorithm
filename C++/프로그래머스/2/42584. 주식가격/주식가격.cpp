#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int maxIdx = prices.size();
    vector<int> answer(maxIdx);
    
    stack<pair<int, int>> s; s.push({prices[0], 0});
    for(int i=1; i<maxIdx; i++){
        while(!s.empty() && s.top().first>prices[i]){
            pair<int, int> top = s.top(); s.pop();
            answer[top.second] = i-top.second;
        }
        s.push({prices[i], i});
    }
    
    while(!s.empty()){
        pair<int, int> top = s.top(); s.pop();
        answer[top.second] = maxIdx-1-top.second;
    }
    
    return answer;
}