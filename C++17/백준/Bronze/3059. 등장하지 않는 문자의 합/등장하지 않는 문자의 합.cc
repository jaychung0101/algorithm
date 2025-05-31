#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        string s; cin >> s;
        bool chars[91];
        memset(chars, 0, sizeof(chars));
        for(char c : s){
            if(chars[int(c)]) continue;
            chars[int(c)] = 1;
        }
        
        int answer = 0;
        for(int i=65; i<91; i++){
            if(!chars[i]) answer += i;
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}