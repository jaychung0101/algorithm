#include <iostream>
using namespace std;

int main(){
    int s = 0;
    for(int i=0; i<4; i++){
        int x; cin >> x;
        s += x;
    }
    
    int t = 0;
    for(int i=0; i<4; i++){
        int x; cin >> x;
        t += x;
    }
    
    cout << max(s, t);
    
    return 0;
}