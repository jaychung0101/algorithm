//공항
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x){
    if(parent[x]==x){
        return x;
    }

    return parent[x]=find(parent[x]);
}

bool merge(int x){
    x = find(x);
    int y = find(x-1);

    if(x==0) {
        return false;
    } else {
        parent[x] = y;
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int G, P; cin >> G >> P;
    parent.resize(G+1);
    for(int i=0; i<G+1; i++){
        parent[i] = i;
    }

    vector<int> planes(P);
    for(int &plane : planes) cin >> plane;

    int answer = 0;
    for(int i=0; i<P; i++){
        if(!merge(planes[i])){
            break;
        };
        answer++;
    }

    cout << answer;

    return 0;
}