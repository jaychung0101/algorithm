//행렬 제곱
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Matrix;

ll N, B;
ll MOD_NUM = 1000;
Matrix matrix;
Matrix answer;

Matrix matrixMulti(Matrix &m1, Matrix &m2){
    Matrix result(N, vector<ll>(N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
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

    cin >> N >> B;
    matrix.resize(N, vector<ll>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
        }
    }

    answer.resize(N, vector<ll>(N, 0));
    for(int i=0; i<N; i++) answer[i][i] = 1;

    while(B){
        if(B & 1LL){
            answer = matrixMulti(answer, matrix);
        }
        matrix = matrixMulti(matrix, matrix);
        B >>= 1;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }   
}