// N과 M (5)
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int ans[10];
int list[10];
bool used[10];

void backTracking(int size){
    if(size==M){
        for(int i=0; i<M; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=0; i<N; i++){
        if(used[i]==0){
            used[i] = true;
            ans[size] = list[i];
            backTracking(size+1);
            used[i] = false;
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> list[i];

    sort(list, list+N);

    backTracking(0);

    return 0;
}