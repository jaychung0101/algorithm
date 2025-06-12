//두 배열의 합
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;

    int n; cin >> n;
    vector<int> A(n);
    for(int &x : A) cin >> x;

    int m; cin >> m;
    vector<int> B(m);
    for(int &x : B) cin >> x;

    unordered_map<int, long> mapA;
    for(int i=0; i<n; i++){
        int sum = A[i];
        if(!mapA.count(sum)) mapA[sum] = 1;
        else mapA[sum]++;

        for(int j=i+1; j<n; j++){
            sum += A[j];
            if(!mapA.count(sum)) mapA[sum] = 1;
            else mapA[sum]++;
        }
    }
    
    unordered_map<int, long> mapB;
    for(int i=0; i<m; i++){
        int sum = B[i];
        if(!mapB.count(sum)) mapB[sum] = 1;
        else mapB[sum]++;

        for(int j=i+1; j<m; j++){
            sum += B[j];
            if(!mapB.count(sum)) mapB[sum] = 1;
            else mapB[sum]++;
        }
    }

    long answer = 0;
    for(auto [key, value] : mapA){
        if(mapB.count(T-key)) {
            answer += value*mapB[T-key];
        }
    }

    cout << answer;
    
    return 0;
}
