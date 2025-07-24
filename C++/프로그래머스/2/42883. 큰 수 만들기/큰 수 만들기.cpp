#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int num = number.length() - k;
    int idx = 0;
    
    for(int i=0; i<num; i++){
        char maxChar = number[idx];
        int maxIdx = idx;

        for(int j = idx; j <= k+i; j++){
            if(maxChar < number[j]){
                maxChar = number[j];
                maxIdx = j;
            }
        }
        answer += maxChar;
        idx = maxIdx + 1;
    }
    
    return answer;
}