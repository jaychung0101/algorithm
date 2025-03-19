// 부녀회장이 될 테야
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> h(15, vector<int>(15, 0));

int cal(int k, int n){
    if(!h[k][n]){
        for(int i=1; i<=n; i++){
            h[k][n] += cal(k-1, i);
        }
    }
    
    return h[k][n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i=1; i<=14; i++) h[0][i] = i;

    int T; cin >> T;
    while(T--){
        int k, n; cin >> k >> n;
        cout << cal(k, n) << '\n';
    }
}