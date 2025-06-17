//텀 프로젝트
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int answer = N;
        vector<int> students(N+1);
        vector<int> state(N+1, 0); //0:방문 안함, 1:처음 방문, 2:방문 해봄/사이클 없음, 3:방문 해봄/사이클 있음
        for(int i=1; i<N+1; i++) cin >> students[i];

        for(int i=1; i<N+1; i++){
            if(state[i]==2 || state[i]==3) continue;

            int current = i;
            while(!state[current]){
                state[current] = 1;
                current = students[current];
            }

            //1이었는데 멈춤 -> 처음 발견하는 사이클
            if(state[current]==1){
                current = i;
                while(state[current]==1){ //모두 사이클이 없다고 마킹
                    state[current] = 2;
                    current = students[current];
                }

                state[current] = 3;
                answer--;

                if(students[current]==current) continue;

                current = students[current];
                while(state[current]==2){
                    state[current] = 3;
                    answer--;
                    current = students[current];
                }
            } else{
                current = i;
                while(state[current]!=2){ //모두 사이클이 없다고 마킹
                    state[current] = 2;
                    current = students[current];
                }
            }
        }
        cout << answer << '\n';
    }
}