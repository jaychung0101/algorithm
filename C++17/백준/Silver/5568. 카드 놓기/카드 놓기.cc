//카드 놓기
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n, k; 

vector<string> v;
vector<string> answer;
vector<bool> used;
unordered_set<string> s;

void backtracking(int size){
    if(answer.size()==k){
        string temp = "";
        for(string x : answer){
            temp += x;
        }

        s.insert(temp);
    }

    for(int i=0; i<n; i++){
        if(used[i]) continue;
        
        used[i] = true;
        answer.push_back(v[i]);
        backtracking(size+1);
        answer.pop_back();
        used[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    v.resize(n);
    used.resize(n, false);
    for(string &x : v){
        cin >> x;
    }

    backtracking(0);

    cout << s.size();

    return 0;
}