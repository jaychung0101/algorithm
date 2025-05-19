//가장 긴 증가하는 부분 수열 5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> v(N), LIS, LIS_size(N);

    for(int &x : v) cin >> x;

    int max_size = 0;
    for(int i=0; i<N; i++){
        auto it = lower_bound(LIS.begin(), LIS.end(), v[i]);

        LIS_size[i] = it - LIS.begin();
        max_size = max(max_size, LIS_size[i]);

        if(it==LIS.end()) {
            LIS.push_back(v[i]);
        } else{
            *it = v[i];
        }
    }

    int current = max_size;
    vector<int> answer(max_size+1);
    for(int i=N-1; i>=0; i--){
        if(LIS_size[i]==current){
            if(current==max_size){
                answer[current] = v[i];
                current--;
            } else{
                if(v[i]<answer[current+1]){
                    answer[current] = v[i];
                    current--;
                }
            }
        }
    }

    cout << max_size+1 << '\n';
    for(int x : answer) cout << x << ' ';

    return 0;
}