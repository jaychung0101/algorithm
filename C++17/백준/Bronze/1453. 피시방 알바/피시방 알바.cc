//피시방 알바
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool seat[101];
    fill(seat, seat+sizeof(bool)*101, 0);

    int N; cin >> N;
    int answer = 0;

    while(N--){
        int x; cin >> x;
        if(seat[x]) answer++;
        seat[x] = true;
    }

    cout << answer;

    return 0;
}