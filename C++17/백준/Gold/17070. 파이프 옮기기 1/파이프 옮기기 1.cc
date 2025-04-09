//파이프 옮기기 1
#include <iostream>
#include <vector>
using namespace std;

#define WIDTH 0
#define LENGTH 1
#define DIAGONAL 2

int N, answer; 
vector<vector<bool>> home;

void move(int cx, int cy, int how){
    if(cx==N-1 && cy==N-1){
        answer++;
        return;
    }

    bool flag1 = false, flag2 = false, flag3 = false;
    if(cy+1<N && !home[cx][cy+1]) flag1 = true;
    if(cx+1<N && !home[cx+1][cy]) flag2 = true;
    if(flag1 && flag2 && !home[cx+1][cy+1]) flag3 = true;

    if(how==WIDTH){
        if(flag1) move(cx, cy+1, WIDTH);
        if(flag3) move(cx+1, cy+1, DIAGONAL);
    } else if(how==LENGTH){
        if(flag2) move(cx+1, cy, LENGTH);
        if(flag3) move(cx+1, cy+1, DIAGONAL);
    } else{
        if(flag1) move(cx, cy+1, WIDTH);
        if(flag2) move(cx+1, cy, LENGTH);
        if(flag3) move(cx+1, cy+1, DIAGONAL);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    home.resize(N, vector<bool>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            bool value; cin >> value;
            home[i][j] = value;
        }
    }

    move(0, 1, WIDTH);
    cout << answer;

    return 0;
}