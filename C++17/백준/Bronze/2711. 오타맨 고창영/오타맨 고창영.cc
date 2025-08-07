#include <iostream>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int l;
        string s;
        cin >> l >> s;
        for(int i=0; i<s.size(); i++){
            if(i+1==l) continue;
            cout << s[i];
        }
        cout << '\n';
    }
    
    return 0;
}