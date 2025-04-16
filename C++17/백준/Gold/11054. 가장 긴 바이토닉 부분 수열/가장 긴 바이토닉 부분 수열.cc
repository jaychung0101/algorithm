//가장 긴 바이토닉 부분 수열
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> v(N);
    for(int &x : v) cin >> x;
    
    vector<int> lis1(N), lis2(N), temp;
    for(int i=0; i<N; i++){
        auto it = lower_bound(temp.begin(), temp.end(), v[i]);
        lis1[i] = it-temp.begin()+1;
        if(it==temp.end()) temp.push_back(v[i]);
        else *it = v[i];
    }

    temp.clear();
    for(int i=0; i<N; i++){
        auto it = lower_bound(temp.begin(), temp.end(), v[N-1-i]);
        lis2[N-1-i] = it-temp.begin()+1;
        if(it==temp.end()) temp.push_back(v[N-1-i]);
        else *it = v[N-1-i];
    }

    int answer = 0;
    for(int i=0; i<N; i++){
        answer = max(answer, lis1[i]+lis2[i]-1);
    }

    cout << answer;

    return 0;
}