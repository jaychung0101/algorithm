// N과 M (4)
#include <iostream>
#include <vector>
using namespace std;

int N, M; 
vector<bool> used;

void backTracking(vector<int> &answer, int cur){
    if(answer.size()==M){
        for(int x : answer){
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=cur; i<=N; i++){
        answer.push_back(i);
        backTracking(answer, i);
        answer.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    used.resize(N+1, false);

    vector<int> answer;
    backTracking(answer, 1);

    return 0;
}