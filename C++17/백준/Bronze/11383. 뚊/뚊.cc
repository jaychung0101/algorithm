//뚊
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<char>> v(N, vector<char>(M+1)), w(N, vector<char>(2*M+1));
    
    for(int i=0; i<N; i++){
        for(int j=1; j<=M; j++){
            cin >> v[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=1; j<=2*M; j++){
            cin >> w[i][j];
        }
    }

    bool flag = true;
    for(int i=0; i<N; i++){
        for(int j=1; j<=M; j++){
            if(v[i][j]==w[i][2*j-1] && v[i][j]==w[i][2*j]) continue;
            flag = false;
        }
    }

    cout << (flag ? "Eyfa" : "Not Eyfa");

    return 0;
}