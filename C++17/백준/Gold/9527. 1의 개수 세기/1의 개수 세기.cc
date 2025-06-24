//1의 개수 세기
#include <iostream>
using namespace std;

long long count1(long long num){
    if(num==0) return 0;
    if(num==1) return 1;

    long long k = 1, powK = 1, current = 0, count = 0;
    if(num&1){
        current = 1;
        count = 1;
    }
    num >>= 1;

    while(num){
        if(num&1){
            current += powK*2;
            count += powK*k + (current-powK*2) + 1;
        }

        num >>= 1;
        powK *= 2;
        k++;
    }

    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    long long A, B; cin >> A >> B;

    cout << count1(B) - count1(A-1);

    return 0;
}