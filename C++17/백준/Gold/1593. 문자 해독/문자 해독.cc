// 문자 해독
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int g, s;
    cin >> g >> s;

    vector<int> clist(123, 0);
    for(int i=0; i<g; i++){
        char c;
        cin >> c;
        clist[(int)c]++;
    }

    vector<int> comp(123, 0);
    string S;
    cin >> S;
    for(int r=0; r<g; r++) comp[(int)S[r]]++;

    int cnt = 0, l = 0;
    bool same = false;
    if(comp == clist){
        cnt++;
        same = true;
    }
    for(int r=g; r<s; r++){
        if(same==true){
            if(S[r]==S[l]) cnt++;
            else same = false;
            comp[(int)S[r]]++;
            comp[(int)S[l++]]--;
        }
        else{
            comp[(int)S[r]]++;
            comp[(int)S[l++]]--;
            if(comp == clist){
                same = true;
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}