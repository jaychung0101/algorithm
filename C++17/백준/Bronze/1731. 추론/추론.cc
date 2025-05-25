//추론
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> v(N);

    for(int &x : v) cin >> x;

    int temp1 = v[1] - v[0];
    bool flag = false;
    for(int i=1; i<N; i++){
        if(v[i]-v[i-1]!=temp1) break;
        if(i==N-1){
            cout << v[N-1] + temp1;
            flag = true;
        }
    }

    int temp2 = v[1] / v[0];
    for(int i=1; i<N; i++){
        if(v[i]/v[i-1]!=temp2) break;
        if(i==N-1 && !flag) cout << v[N-1] * temp2;
    }

    return 0;
}