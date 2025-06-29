//8진수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s[9] = {"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};

    int N; cin >> N;
    vector<int> candidate(9);
    for(int i=0; i<9; i++){
        int max_p = -1;
        for(int j=0; j<N; j++){
            int x; cin >> x;
            max_p = max(max_p, x);
        }

        candidate[i] = max_p;
    }

    int max_f = -1, idx = -1;
    for(int i=0; i<9; i++){
        if(max_f < candidate[i]){
            max_f = candidate[i];
            idx = i;
        }
    }

    cout << s[idx];

    return 0;
}