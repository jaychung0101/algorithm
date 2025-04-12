#include <iostream>
using namespace std;

int num[10];

int main(){
    int a, b, c; cin >> a >> b >> c;
    int mult = a*b*c;
    
    while(mult){
        num[mult%10]++;
        mult /= 10;
    }

    for(int x : num) cout << x << '\n';
}