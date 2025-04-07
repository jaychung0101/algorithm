// 문자열 폭발
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string N, M; cin >> N >> M;
    stack<char> sk;

    char last = M[M.size()-1];

    bool flag = false;
    for(char x : N){
        sk.push(x);
        if(x!=last) continue;

        if(sk.size()>=M.size()){
            string temp;
            for(int i=0; i<M.size(); i++){
                temp.push_back(sk.top()); sk.pop();
            }

            reverse(temp.begin(), temp.end());
            if(temp!=M){
                for(int i=0; i<temp.size(); i++){
                    sk.push(temp[i]);
                }
            }
        }
    }

    if(sk.empty()) cout << "FRULA";
    else{
        string temp;
        while(!sk.empty()){
            temp.push_back(sk.top()); sk.pop();
        }
        reverse(temp.begin(), temp.end());
        cout << temp;
    }

    return 0;
}