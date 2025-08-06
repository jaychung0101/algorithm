#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T; cin >> T;
    while(T--){
        int a=0, b=0;
        
        for(int i=0; i<9; i++){
            int x, y; cin >> x >> y;    
            a += x;
            b += y;
        }
        
        if(a>b) cout << "Yonsei";
        else if(a<b) cout << "Korea";
        else cout << "Draw";
        cout << '\n';
    }
    
    return 0;
}