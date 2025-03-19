// ZOAC 6
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int res = 0;
    while(N--){
        string s; cin >> s;
        for(int i=0; i<s.size()-1; i++){
            if((s[i]=='0' && s[i+1]=='1') || (s[i]=='O' && s[i+1] == 'I')){
                res++;
                break;
            }
        }
    }
    cout << res;
    return 0;
}