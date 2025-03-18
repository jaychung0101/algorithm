// N과 M (2)
#include <iostream>
#include <vector>
using namespace std;

int N, M;

void backTracking(vector<int> &v, int idx, int size){
    if(size==M){
        for(int i=0; i<M; i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    if(idx>=N) return;

    
    v[size] = idx+1;
    backTracking(v, idx+1, size+1);
    backTracking(v, idx+1, size);
}

int main(){
    cin >> N >> M;
    vector<int> res(N);
    backTracking(res, 0, 0);
}