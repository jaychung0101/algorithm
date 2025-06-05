//수 나누기 게임
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int score[1000001];
    bool check[1000001];
    memset(score, 0, sizeof(score));

    int N; cin >> N;
    vector<int> cards(N);
    for(int i=0; i<N; i++){
        cin >> cards[i];
        check[cards[i]] = true;
    }

    for(int i=0; i<N; i++){
        int number = cards[i];
        for(int j=number*2; j<1000001; j+=number){
            if(!check[j]) continue;

            score[number]++;
            score[j]--;
        }
    }

    for(int i=0; i<N; i++){
        cout << score[cards[i]] << ' ';
    }

    return 0;
}