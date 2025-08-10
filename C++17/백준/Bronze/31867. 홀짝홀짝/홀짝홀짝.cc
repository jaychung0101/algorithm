#include <iostream>
using namespace std;

int main(){
    int N; cin >> N;
    string s; cin >> s;
    
    int e = 0, o = 0;
    for(char c : s){
        if(c=='1' || c=='3' || c=='5' || c=='7' || c=='9'){
            o++;
        } else{
            e++;
        }
    }
    
    if(o<e){
        cout << 0;
    } else if(o>e){
        cout << 1;
    } else{
        cout << -1;
    }
    
    return 0;
}