// 상근이의 친구들
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(true){
        int M, F; cin >> M >> F;
        if(M+F==0) break;
        cout << M+F << '\n';
    }

    return 0;
}