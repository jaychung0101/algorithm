#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int maxSize = citations.size();
    int answer = 0;
    int limit = -1;
    
    for(int i=0; i<maxSize; i++){
        if(citations[i]>maxSize-i){
            limit = maxSize - i;
            break;
        }
        
        answer = citations[i];
    }
    
    if(answer<limit) answer = limit;
    return answer;
}