#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
using piv = pair<int, vector<int>>;

int n, m;
vector<int> a;
vector<int> cura;
vector<tuple<int, int, int>> op;
map<vector<int>, int> visited;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];

    cin >> m;
    op = vector<tuple<int, int, int>>(m);
    for(int i=0; i<m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        op[i] = {l, r, c};
    }

    priority_queue<piv, vector<piv>, greater<piv>> pq;
    pq.emplace(0, a);
    visited[a] = 0;
    while(!pq.empty()){
        auto [cc, cv] = pq.top(); pq.pop();

        for(int i=0; i<m; i++) {
            auto [l, r, cost] = op[i];
            swap(cv[l-1], cv[r-1]);
            if(!visited.count(cv) || cc+cost < visited[cv]){
                visited[cv] = cc + cost;
                pq.emplace(cc + cost, cv);
            }
            swap(cv[l-1], cv[r-1]);
        }
    }

    sort(a.begin(), a.end());

    if (visited.count(a)) cout << visited[a];
    else cout << -1;

    return 0;
}