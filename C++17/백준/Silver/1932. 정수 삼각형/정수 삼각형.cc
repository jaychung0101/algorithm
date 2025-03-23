// 정수 삼각형
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; 
vector<int> input, answer;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    input.resize(N+2); answer.resize(N+2, 0);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++) cin >> input[j];

        vector<int> temp = answer;
        for(int j=1; j<=i; j++) answer[j] = max(temp[j-1], temp[j]) + input[j];
    }

    sort(answer.begin(), answer.end());
    cout << answer[answer.size()-1];

    return 0;
}