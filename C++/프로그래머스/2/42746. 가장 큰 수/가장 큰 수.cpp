#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string x, string y){
    return x+y > y+x;
}
string solution(vector<int> numbers) {
    vector<string> v(numbers.size());
    for(int i=0; i<numbers.size(); i++){
        v[i] = to_string(numbers[i]);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    string answer = "";
    for(string number : v){
        answer += number;
    }
    
    if(v[0]=="0") answer = "0";
    
    return answer;
}