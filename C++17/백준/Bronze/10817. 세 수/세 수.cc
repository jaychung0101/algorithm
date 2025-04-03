// 세 수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int a, b, c; cin >> a >> b >> c;

    if(a<b){
        if(a<c){
            if(b<c){
                cout << b;
            } else{
                cout << c;
            }
        } else{
            cout << a;
        }
    } else{
        if(c<b){
            cout << b;
        } else{
            if(a<c){
                cout << a;
            } else{
                cout << c;
            }
        }
    }
    
    return 0;
}