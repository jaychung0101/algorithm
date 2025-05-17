//가장 가까운 공통 조상
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> v(N+1, -1);
        for(int i=1; i<N; i++){
            int A, B; cin >> A >> B;
            v[B] = A;
        }

        int n1, n2; cin >> n1 >> n2;
        set<int> parent;

        int current = n1;
        while(v[current]!=-1){
            parent.insert(current);
            current = v[current];
        }
        parent.insert(current);

        current = n2;
        while(true){
            if(parent.count(current)){
                cout << current << '\n';
                break;
            }
            current = v[current];
        }
    }
}