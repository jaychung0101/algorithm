#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> v = score;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        if((i+1)%m==0) answer += v[i]*m;
    }
    
    return answer;
}