#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T; cin >> T;
    while(T--){
        string s; cin >> s;
        int answer = 0;
        for(char c : s){
            if(c!='U') break;
            answer++;
        }
        cout << answer << '\n';
    }
    
    return 0;
}