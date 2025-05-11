#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N; cin >> N;
    vector<int> v(10001, 0);
    for(int i=0; i<N; i++){
        int x; cin >> x;
        v[x]++;
    }
    
    for(int i=1; i<10001; i++){
        while(v[i]--) cout << i << '\n';
    }
    
    return 0;
}