//거짓말
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<bool>> party(M, vector<bool>(N+1, false)); //파티에 참여한 사람들
    vector<bool> truthParty(M, false); //진실을 말해야 되는 파티
    set<int> truthPeople; //진실을 아는 사람

    int num; cin >> num;
    while(num--){
        int p; cin >> p;
        truthPeople.insert(p);
    }

    for(int i=0; i<M; i++){
        int n; cin >> n;
        while(n--){
            int p; cin >> p;
            party[i][p] = true;
        }
    }

    bool flag = false;
    while(!flag){
        flag = true;
        for(int i=0; i<M; i++){
            if(truthParty[i]) continue;

            for(int x : truthPeople){
                if(party[i][x]){
                    flag = false;
                    truthParty[i] = true;
                    for(int j=1; j<party[i].size(); j++){
                        if(party[i][j]) truthPeople.insert(j);
                    }
                    break;
                }
            }
        }
    }

    int answer = 0;
    for(bool x : truthParty){
        if(!x) answer++;
    }

    cout << answer;

    return 0;
}