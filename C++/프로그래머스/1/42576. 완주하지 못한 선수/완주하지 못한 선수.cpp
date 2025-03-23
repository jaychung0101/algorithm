#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    bool flag = false;
    for(int idx=0; idx<completion.size(); idx++){
        if(participant[idx]!=completion[idx]){
            answer = participant[idx];
            flag = true;
            break;
        }
    }
    
    if(!flag){
        answer = participant[participant.size()-1];
    }
    
    return answer;
}