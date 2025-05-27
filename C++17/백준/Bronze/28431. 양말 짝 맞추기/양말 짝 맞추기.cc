#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<bool> v(10, 0);

    for(int i=0; i<5; i++){
        int x; cin >> x;
        if(v[x]) v[x] = 0;
        else v[x] = 1;
    }
    
    for(int i=0; i<10; i++){
        if(v[i]) cout << i;
    }
    
    return 0;
}