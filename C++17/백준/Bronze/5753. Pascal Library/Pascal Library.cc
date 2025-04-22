//Pascal Libary
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(true){
        int N, D; cin >> N >> D;

        if(N==0 && D==0) break;
        
        vector<bool> v(N, true);    
        while(D--){
            for(int i=0; i<N; i++){
                int a; cin >> a;
                if(!a) v[i] = false;
            }
        }

        bool flag = false;
        for(bool x : v){
            if(x){
                flag = true;
                break;
            }
        }

        cout << (flag ? "yes" : "no") << '\n';
    }
}