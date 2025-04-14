// 별 찍기 - 11
#include <iostream>
using namespace std;

int N;
char coor[3073][6144];

void draw(int x, int y, int size) {
    if(size==3){
        coor[x][y] = '*';
        coor[x+1][y-1] = coor[x+1][y+1] = '*';
        for (int i=-2; i<=2; i++) coor[x+2][y+i] = '*';
        return;
    }

    int half = size/2;
    draw(x, y, half);
    draw(x+half, y-half, half);
    draw(x+half, y+half, half);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i=0; i<3073; i++){
        for(int j=0; j<6144; j++){
            coor[i][j] = ' ';
        }
    }

    int N; cin >> N;
    draw(0, N-1, N);

    for(int i=0; i<N; i++){
        for(int j=0; j<2*N; j++){
            cout << coor[i][j];
        }
        cout << '\n';
    }
}