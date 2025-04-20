//가장 큰 금민수
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=N; i>0; i--){
        bool flag = true;
        int k = i;
        while(k){
            if(k%10==4 || k%10==7){
                k/=10;
                continue;
            }
            flag = false;
            break;
        }
        
        if(flag){
            cout << i;
            break;
        }
    }
}