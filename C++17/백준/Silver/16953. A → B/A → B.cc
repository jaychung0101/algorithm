//A → B
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

long long A, B; 

int process(long long A){
    deque<long long> q;
    q.push_back(A);

    int cnt = 0;
    while(!q.empty()){
        cnt++;

        deque<long long> temp;
        for(long long x : q){
            if(x==B){
                return cnt;
            }
            long long mult = x*2;
            long long right = x*10 + 1;
            if(mult<=B) temp.push_back(mult);
            if(right<=B) temp.push_back(right);    
        }
        q = temp;
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> A >> B;
    cout << process(A);

    return 0;
}