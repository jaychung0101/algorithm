//사전 순 최대 공통 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; 
    
    cin >> N;
    vector<int> v1(N);
    for(int &x : v1) cin >> x;

    cin >> M;
    vector<int> v2(M);
    for(int &x : v2) cin >> x;

    vector<int> temp = v1;
    
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());

    vector<int> answer;
    auto it1 = v1.begin(), it2 = v2.begin();
    auto tempIt1 = it1, tempIt2 = it2;
    for(int x : temp){
        tempIt2 = find(it2, v2.end(), x);
        if(tempIt2==v2.end()) continue;
        tempIt1 = find(it1, v1.end(), x);
        if(tempIt1==v1.end()) continue;
        
        it1 = tempIt1+1;
        it2 = tempIt2+1;

        answer.push_back(x);
    }

    cout << answer.size() << '\n';      
    for(int x : answer) cout << x << ' ';

    return 0;
}