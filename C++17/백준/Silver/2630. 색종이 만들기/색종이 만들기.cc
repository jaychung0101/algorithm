// 색종이 만들기
#include <iostream>
#include <vector>
using namespace std;

int blue, white;

void half(vector<vector<bool>> &map, int x, int y, int N){
    bool color = map[x][y];

    if(N==1){
        if(color) blue++;
        else white++;
        return;
    }

    bool flag = true;
    for(int i=x; i<x+N; i++){
        for(int j=y; j<y+N; j++){
            if(map[i][j]!=color){
                flag = false;
                break;
            }
        }
    }

    if(flag){
        if(color) blue++;
        else white++;
    }
    else{
        half(map, x, y, N/2);
        half(map, x+N/2, y, N/2);
        half(map, x, y+N/2, N/2);
        half(map, x+N/2, y+N/2, N/2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<vector<bool>> map(N, vector<bool>(N));

    bool input;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> input;
            map[i][j] = input;
        }
    }

    half(map, 0, 0, N);
    cout << white << '\n' << blue;
    
    return 0;
}