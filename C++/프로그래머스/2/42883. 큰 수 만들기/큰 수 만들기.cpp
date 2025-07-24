#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(string number, int k) {
    deque<char> d;
    
    for(char c : number){
        while(d.size() && k && d.back()<c){
            d.pop_back();
            k--;
        }
        d.push_back(c);
    }
    
    string answer(d.begin(), d.end()-k);
    return answer;
}