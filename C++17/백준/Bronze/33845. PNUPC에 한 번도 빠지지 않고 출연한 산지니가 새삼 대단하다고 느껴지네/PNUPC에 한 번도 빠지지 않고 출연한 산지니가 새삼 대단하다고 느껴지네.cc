#include <iostream>
using namespace std;

bool check[26];

int main(){
    string a, b;
    cin >> a >> b;
    
    for(char c : a){
        check[c - 'a'] = true;
    }    
    
    for(char c : b){
        if(check[c - 'a']) continue;
        cout << c;
    }
    
    return 0;
}
