#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T; cin >> T;
    while(T--){
        int scores[5];
        for(int &score : scores){
            cin >> score; 
        }
        
        sort(scores, scores+5);
        
        if(scores[3]-scores[1] >= 4){
            cout << "KIN";
        } else{
            cout << scores[1] + scores[2] + scores[3];
        }
        cout << '\n';
    }
    return 0;
}
