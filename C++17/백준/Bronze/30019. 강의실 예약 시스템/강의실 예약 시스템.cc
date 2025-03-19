// 강의실 예약 시스템
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;

    vector<int> time(N+1, -1);
    while(M--){
        int room, s, e; cin >> room >> s >> e;
        
        if(time[room]==-1){
            time[room] = e;
            cout << "YES\n";
        }
        else{
            if(s<time[room]) cout << "NO\n";
            else{
                time[room] = e;
                cout << "YES\n";
            }
        }
    }

    return 0;
}