//소수의 연속합
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<bool> v(N+1, false);
    vector<int> primes;
    for(int i=2; i<N+1; i++){
        if(v[i]) continue;

        primes.push_back(i);
        for(int j=i*2; j<N+1; j+=i) v[j] = true;
    }

    int answer = 0;
    if(!v[N]) answer += 1;

    for(int i=0; i<primes.size(); i++){
        if(primes[i]>N/2) break;

        int temp = primes[i];
        for(int j=i+1; j<primes.size(); j++){
            temp += primes[j];
            if(temp>=N){
                if(temp==N) answer++;
                break;
            }
        }
    }

    cout << (N==1 ? 0 : answer);
    return 0;
}