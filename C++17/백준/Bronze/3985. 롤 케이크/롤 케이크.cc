//롤 케이크
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int L, N; cin >> L >> N;
    vector<int> piece(N+1, 0);
    vector<bool> cake(L+1, true);

    int max_cake = -1, max_person = 0, max_expectation = -1, max_expectation_person = 0;
    for(int person=1; person<=N; person++){
        int p, k; cin >> p >> k;

        if(k-p > max_expectation){
            max_expectation = k-p;
            max_expectation_person = person;
        }

        for(int i=p; i<=k; i++){
            if(!cake[i]) continue;

            cake[i] = false;
            piece[person]++;
        }

        if(max_cake < piece[person]){
            max_cake = piece[person];
            max_person = person;
        }
    }

    cout << max_expectation_person << '\n';
    cout << max_person;

    return 0;
}