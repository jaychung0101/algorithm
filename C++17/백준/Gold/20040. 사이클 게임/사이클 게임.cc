//사이클 게임
#include <iostream>
#include <vector>
using namespace std;

vector<int> parents;
vector<int> childs;

int find(int x){
    if(parents[x]==x) return x;

    return parents[x] = find(parents[x]);
}

bool merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y) return false;

    if(childs[x]<childs[y]){
        parents[x] = y;
        childs[y] += childs[x];
    } else{
        parents[y] = x;
        childs[x] += childs[y];
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    parents.resize(n);
    childs.resize(n, 1);
    for(int i=0; i<n; i++) parents[i] = i;

    int answer = 0;
    for(int i=1; i<m+1; i++){
        int x, y; cin >> x >> y;
        if(!answer && !merge(x, y)) answer = i;
    }

    cout << answer;

    return 0;
}