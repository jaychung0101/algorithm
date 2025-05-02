//동전 0
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    vector<int> coins;
    while(N--){
        int x; cin >> x;
        coins.push_back(x);
    }

    int answer = 0;
    for(int i=coins.size()-1; i>=0; i--){
        answer += K/coins[i];
        K %= coins[i];
        if(K==0) break;
    }

    cout << answer;

    return 0;
}