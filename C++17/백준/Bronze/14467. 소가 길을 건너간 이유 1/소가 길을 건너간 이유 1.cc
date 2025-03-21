// 소가 길을 건너간 이유 1
#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int res = 0;
    vector<int> cow(11, -1);
    while(N--){
        int cow_num, loc;
        cin >> cow_num >> loc;
        if(cow[cow_num]==-1) cow[cow_num] = loc;
        else{
            if(cow[cow_num]!=loc){
                res++;
                cow[cow_num]=loc;
            }
        }
    }

    cout << res;

    return 0;
}