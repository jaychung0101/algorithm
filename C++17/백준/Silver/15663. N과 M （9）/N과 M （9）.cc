// N과 M(9)
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M; 
vector<int> v;
vector<bool> used;
set<vector<int>> s;

void backTracking(vector<int> &answer){
    if(answer.size()==M){
        s.insert(answer);
        return;
    }

    for(int i=0; i<N; i++){
        if(used[i]) continue;
        used[i] = true;
        answer.push_back(v[i]);
        backTracking(answer);
        used[i] = false;
        answer.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    v.resize(N); used.resize(N, false);
    for(auto &x : v) cin >> x;

    vector<int> answer;
    backTracking(answer);

    for(vector<int> x : s){
        for(int a : x) cout << a << ' ';
        cout << '\n';
    }
}