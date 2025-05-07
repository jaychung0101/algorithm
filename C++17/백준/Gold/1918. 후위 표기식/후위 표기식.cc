//후위 표기식
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

int precedence(string &op) {
    if(op == "*" || op == "/") return 2;
    if(op == "+" || op == "-") return 1;
    return 0;
}

string postFix(deque<string> &q){
    if(q.size()==1) return q.front();

    string returnString;
    stack<string> opstk;
    for(string token : q){
        if(token == "+" || token == "-" || token == "*" || token == "/"){
            while(!opstk.empty() && precedence(opstk.top()) >= precedence(token)){
                returnString.append(opstk.top());
                opstk.pop();
            }
            opstk.push(token);
        } else {
            returnString.append(token);
        }
    }

    while(!opstk.empty()){
        returnString.append(opstk.top());
        opstk.pop();
    }
    
    return returnString;
}

int main(){
    string s; cin >> s;
    deque<pair<string, int>> q;

    int pri = 0;
    int max_pri = 0;
    for(char c : s){
        if(c=='('){
            pri++;
            max_pri = max(max_pri, pri);
            continue;
        }
        if(c==')'){
            pri--;
            continue;
        }

        q.emplace_back(string(1, c), pri);
    }

    while(q.size()>1){
        deque<pair<string, int>> tempQ1;
        deque<string> tempQ2;
        bool flag = false;
        for(auto [op, pri_cnt] : q){
            if(pri_cnt==max_pri){
                flag = true;
                tempQ2.emplace_back(op);
            } else{
                if(flag){
                    tempQ1.emplace_back(postFix(tempQ2), max_pri-1);
                    tempQ2.clear();
                    flag = false;
                }
                
                tempQ1.emplace_back(op, pri_cnt);
            }
        }

        if(!tempQ2.empty()) tempQ1.emplace_back(postFix(tempQ2), max_pri-1);

        max_pri--;
        q = tempQ1;
    }

    cout << q.front().first;

    return 0;
}