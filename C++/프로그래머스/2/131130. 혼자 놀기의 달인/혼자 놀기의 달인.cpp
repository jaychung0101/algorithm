#include <string>
#include <vector>
#include <queue>

using namespace std;

bool used[101];

int solution(vector<int> cards) {
    priority_queue<int> pq;
    pq.push(0);
    
    for(int i=0; i<cards.size(); i++){
        if(used[i+1]) continue;
        
        int cnt = 1;
        int current = cards[i];
        used[current] = true;
        while(!used[cards[current-1]]){
            used[current] = true;
            current = cards[current-1];
            cnt++;
        }
        
        pq.push(cnt);
    }
    
    int answer = pq.top(); pq.pop();
    answer *= pq.top();
    return answer;
}