//계단 수
#include <iostream>
#include <vector>
using namespace std;

int N; 
const int MOD = 1e9;
int dp[101][10][1024];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    if(N>=10){
        for(int i=1; i<=9; i++){
            dp[1][i][1<<i] = 1;
        }

        for(int length=2; length<=N; length++){
            for(int digit=0; digit<=9; digit++){
                for(int bit=0; bit<1024; bit++){
                    if(digit>0){
                        int next = digit - 1;
                        int nextBit = bit | (1<<next);
                        dp[length][next][nextBit] += dp[length-1][digit][bit];
                        dp[length][next][nextBit] %= MOD;
                    }
                    if(digit<9){
                        int next = digit + 1;
                        int nextBit = bit | (1<<next);
                        dp[length][next][nextBit] += dp[length-1][digit][bit];
                        dp[length][next][nextBit] %= MOD;
                    }
                }       
            }
        }
    }

    long long answer = 0;
    for(int i=0; i<=9; i++){
        answer = (answer + dp[N][i][1023])%MOD;
    }

    cout << answer;

    return 0;
}