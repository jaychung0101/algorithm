#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<string>> map;
int solution(vector<vector<string>> clothes) {
    for(vector<string> cloth : clothes){
        if(!map.count(cloth[1])) map[cloth[1]].push_back("null");
        map[cloth[1]].push_back(cloth[0]);
    }
    
    int answer = 1;
    for(auto x : map){
        answer *= x.second.size();
    }
    return answer-1;
}