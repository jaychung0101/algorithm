//카드 공장(Small)
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M; cin >> N >> M;
    vector<pair<int, int>> cards(N);
    vector<bool> as(N, 1);
    for(auto &[f, b] : cards){
        cin >> f >> b;
    }

    while(M--){
        int x; cin >> x;
        for(int i=0; i<N; i++){
            if(as[i]){
                if(cards[i].first <= x){
                    as[i] = false;
                }
            }
            else{
                if(cards[i].second <= x){
                    as[i] = true;
                }
            }
        }
    }

    int answer = 0;
    for(int i=0; i<N; i++){
        if(as[i]){
            answer += cards[i].first;
        } else{
            answer += cards[i].second;
        }
    }

    cout << answer;

    return 0;
}