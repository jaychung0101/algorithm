#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M; cin >> N >> M;
    vector<int> v(N+1, 0);
    
    while(M--){
        int a, b, c; cin >> a >> b >> c;
        for(int i=a; i<=b; i++){
            v[i] = c;
        }
    }
    
    for(int i=1; i<=N; i++) cout << v[i] << ' ';
    return 0;
}