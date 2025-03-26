#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    bool flag = true;
    stack<bool> st;
    for(auto x : s){
        if(x=='(') st.push(true);
        else{
            if(st.empty()){
                answer = false;
                flag = false;
                break;
            }
            st.pop();
        }
    }
    
    if(!flag || !st.empty()) answer = false;

    return answer;
}