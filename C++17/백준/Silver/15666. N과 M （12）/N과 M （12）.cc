//N과 M (12)
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> v;
set<vector<int>> s;
int N, M; 

void backTracking(vector<int> &answer, int idx){
    if(answer.size()==M){
        s.insert(answer);
        return ;
    }
    
    for(int i=idx; i<N; i++){
        answer.push_back(v[i]);
        backTracking(answer, i);
        answer.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    vector<int> answer;
    backTracking(answer, 0);

    for(vector<int> x : s){
        for(int y : x){
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}