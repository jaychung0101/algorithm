#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int b, c; cin >> b >> c;
    
    int s = sqrt(b*b-c);
    
    int a1 = -b+s;
    int a2 = -b-s;
    
    if(a1==a2) cout << a1;
    else{
        cout << min(a1, a2) << ' ' << max(a1, a2);
    }
    
    return 0;
}