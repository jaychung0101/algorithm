#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, L; cin >> N >> L;
    
    int black = 0, cnt = 0;
    while(N--){
        string s; cin >> s;
        
        int tempBlack = 0;
        char pre = ' ';
        for(char c : s){
            if(c==pre) continue;
            
            if(c=='1'){
                tempBlack++;
            }
            pre = c;
        }
        
        if(tempBlack > black){
            black = tempBlack;
            cnt = 1;
        } else if(tempBlack == black){
            cnt++;
        }
    }
    
    cout << black << ' ' << cnt;
    return 0;
}
