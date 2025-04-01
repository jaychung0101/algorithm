// Triangles
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(true){
        int n; cin >> n;
        if(n==0) break;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                cout << "*";
            }
            cout << '\n';
        }
    }

    return 0;
}