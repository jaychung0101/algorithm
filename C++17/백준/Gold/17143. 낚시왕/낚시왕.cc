//낚시왕
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using pii = pair<int, int>;

struct Shark{
    int v;
    int d;
    int size;

    Shark(int v=0, int d=0, int size=0){
        this->v = v;
        this->d = d;
        this->size = size;
    }
};

int R, C, M; 

pii move(int r, int c, Shark &shark){
    int d = shark.d, v = shark.v;
    if(d==1 || d==2){
        v %= 2 * (R-1);
        while(v--){
            if(d==1){
                if(r==1){
                    d = 2;
                    r++;
                } else{
                    r--;
                }
            } else{
                if(r==R){
                    d = 1;
                    r--;
                } else{
                    r++;
                }
            }
        }
    } else{
        v %= 2 * (C-1);
        while(v--){
            if(d==3){
                if(c==C){
                    d = 4;
                    c--;
                } else{
                    c++;
                }
            } else{
                if(c==1){
                    d = 3;
                    c++;
                } else{
                    c--;
                }
            }
        }
    }
    
    shark.d = d;
    return {r, c};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> M;
    vector<vector<Shark>> sea(R+1, vector<Shark>(C+1, Shark()));

    while(M--){
        int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
        sea[r][c] = Shark(s, d, z);
    }

    // for(int i=1; i<=R; i++){
    //     for(int j=1; j<=C; j++){
    //         cout << sea[i][j].v << sea[i][j].d << sea[i][j].size << '\t';
    //     }
    //     cout << '\n';
    // }
    
    // return 0;
    
    int loc = 0, answer = 0;
    while(++loc<C+1){
        for(int r=1; r<R+1; r++){
            if(sea[r][loc].size){
                answer += sea[r][loc].size;
                sea[r][loc] = Shark();
                break;
            }
        }

        vector<vector<Shark>> temp(R+1, vector<Shark>(C+1, Shark()));
        for(int r=1; r<R+1; r++){
            for(int c=1; c<C+1; c++){
                if(!sea[r][c].size) continue;

                Shark shark = sea[r][c];
                pii next = move(r, c, shark);

                if(temp[next.first][next.second].size<shark.size){
                    temp[next.first][next.second] = shark;
                }
            }
        }

        sea = temp;
    }

    cout << answer;
    return 0;
}