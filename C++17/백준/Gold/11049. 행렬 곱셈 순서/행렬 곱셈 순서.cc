//행렬 곱셈
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<pair<int, int>> matrix(N+1);
    for(int i=1; i<N+1; i++){
        cin >> matrix[i].first >> matrix[i].second;
    }

    vector<vector<int>> opt(N+1, vector<int>(N+1, INT32_MAX));

    for(int i=1; i<N+1; i++){
        opt[i][i] = 0;
    }

    for(int size=1; size<N; size++){
        for(int row=1; row<N; row++){
            int column = row+size;
            if(column>N) break;

            for(int k=row; k<column; k++){
                opt[row][column] = min(opt[row][column], opt[row][k] + opt[k+1][column] + matrix[row].first*matrix[k].second*matrix[column].second);
            }
        }
    }

    cout << opt[1][N];
    return 0;
}