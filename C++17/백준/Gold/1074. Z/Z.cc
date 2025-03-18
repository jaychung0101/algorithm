// Z
#include <iostream>
using namespace std;

int loc(int n, int r, int c){
    if(n==0) return 0;

    int half_size = 1;
    for(int i=0; i<n-1; i++){
        half_size *= 2;
    }

    if(r<half_size && c<half_size){
        return loc(n-1, r, c);
    } else if(r<half_size && c>=half_size){
        return loc(n-1, r, c-half_size) + half_size * half_size;
    } else if(r>=half_size && c<half_size){
        return loc(n-1, r-half_size, c) + half_size * half_size * 2;
    } else{
        return loc(n-1, r-half_size, c-half_size) + half_size * half_size * 3;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c; cin >> N >> r >> c;
    cout << loc(N, r, c);

    return 0;
}