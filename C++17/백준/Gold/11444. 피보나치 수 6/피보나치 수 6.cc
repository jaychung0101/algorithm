//피보나치 수 6
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Matrix;

ll MOD_NUM = 1000000007;

Matrix matrixMulti(Matrix &m1, Matrix &m2){
    Matrix result(2, vector<ll>(2, 0));

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                result[i][j] += (m1[i][k]*m2[k][j])%MOD_NUM;
            }
            result[i][j] %= MOD_NUM;
        }
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    Matrix matrix = {{1, 1}, {1, 0}};
    Matrix answer = {{1, 0}, {0, 1}};
    while(n){
        if(n & 1LL){
            answer = matrixMulti(answer, matrix);
        }
        matrix = matrixMulti(matrix, matrix);
        n >>= 1;
    }
    
    cout << answer[0][1];

    return 0;
}