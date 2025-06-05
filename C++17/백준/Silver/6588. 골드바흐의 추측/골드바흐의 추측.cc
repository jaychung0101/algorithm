// 골드바흐의 추측
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prime;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> v;
    int k, max = -1;
    while(true){
        cin >> k;
        if(k==0) break;
        else if(k > max)
            max = k;
        v.push_back(k);
    }

    vector<bool> er(max+1, 0);
    for(int i=2; i<max+1; i++){
        if(er[i]) continue;
        prime.push_back(i);
        for(int j=i*2; j<max+1; j+=i){
            er[j] = true;
        }
    }

    for(int a : v){
        for(int i=0; i<prime.size(); i++){
            if(a < prime[i]){
                cout << "Goldbach's conjecture is wrong.";
                break;
            }
            else if(er[a-prime[i]]==false){
                cout << a << " = " << prime[i] << " + " << a-prime[i] << '\n';
                break;
            }
        }
    }

    return 0;
}