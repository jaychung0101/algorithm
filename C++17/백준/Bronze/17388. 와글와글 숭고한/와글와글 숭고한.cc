#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c; cin >> a >> b >> c;
    if(a+b+c>=100){
        cout << "OK";
    } else{
        int k = min({a, b, c});
        if(k==a){
            cout << "Soongsil";
        } else if(k==b){
            cout << "Korea";
        } else{
            cout << "Hanyang";
        }
    }
    
    return 0;
}