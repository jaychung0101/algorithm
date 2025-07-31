#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int N;
vector<vector<pii>> planets;
vector<int> group;
vector<int> child;

int find(int x){
    if(group[x]==x) return x;
    return group[x] = find(group[x]);
}

int merge(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x==y) return 0;
    
    if(child[x]>child[y]){
        group[y] = x;
        child[x] += child[y];
    } else{
        group[x] = y;
        child[y] += child[x];
    }
    
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    planets.resize(3, vector<pii>(N));
    group.resize(N);
    child.resize(N, 1);
    
    for(int i=0; i<N; i++){
        group[i] = i;
        cin >> planets[0][i].first >> planets[1][i].first >> planets[2][i].first;
        planets[0][i].second = i;
        planets[1][i].second = i;
        planets[2][i].second = i;
    }
    
    sort(planets[0].begin(), planets[0].end());
    sort(planets[1].begin(), planets[1].end());
    sort(planets[2].begin(), planets[2].end());
    
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    for(int axis=0; axis<3; axis++){
        for(int i=0; i<N-1; i++){
            int cost = abs(planets[axis][i].first - planets[axis][i+1].first);
            int u = planets[axis][i].second;
            int v = planets[axis][i+1].second;
            pq.emplace(cost, u, v);
        }
    }
    
    int cnt = 0, answer = 0;
    while(cnt<N-1){
        auto [d, p1, p2] = pq.top(); pq.pop();
        if(merge(p1, p2)){
            answer += d;
            cnt++;
        }
    }
    
    cout << answer;
    
    return 0;
}