//사과
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, answer = 0; cin >> N;
    while(N--){
        int x, y; cin >> x >> y;
        answer += y%x;
    }

    cout << answer;

    return 0;
}