#include <iostream>
using namespace std;

int main(){
    int x; cin >> x;
    
    int sum = 0;
    while(x){
        int y = x%10;
        sum += y*y*y*y*y;
        x /= 10;
    }
    
    cout << sum;
    
    return 0;
}