// 달팽이는 올라가고 싶다
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A, B, V, answer; cin >> A >> B >> V;
    answer = 1 + (V-A)/(A-B);
    if((V-A)%(A-B)!=0) answer++;
    cout << answer;
    return 0;
}