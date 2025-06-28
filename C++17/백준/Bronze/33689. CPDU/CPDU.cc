#include <iostream>
using namespace std;

int main(){
    int N; cin >> N;
    
    int answer = 0;
    while(N--){
        string s; cin >> s;
        if(s[0]=='C') answer++;
    }
    
    cout << answer;
    
    return 0;
}