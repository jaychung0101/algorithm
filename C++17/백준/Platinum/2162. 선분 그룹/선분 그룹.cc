// 선분 교차
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int N; 
vector<pair<pii, pii>> lines;
vector<int> group;
vector<int> child;

int ccw(pii p1, pii p2, pii p3){
    int loc = (p2.first-p1.first)*(p3.second-p1.second) - (p3.first-p1.first)*(p2.second-p1.second);

    if(loc < 0) return -1;
    else if(loc > 0) return 1;
    else return 0;
}

bool cross(pair<pii, pii> l1, pair<pii, pii> l2) {
    pii A = l1.first, B = l1.second;
    pii C = l2.first, D = l2.second;

    int ab_c = ccw(A, B, C);
    int ab_d = ccw(A, B, D);
    int cd_a = ccw(C, D, A);
    int cd_b = ccw(C, D, B);

    if (ab_c == 0 && ab_d == 0 && cd_a == 0 && cd_b == 0) {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        return !(B < C || D < A);
    }

    return ab_c * ab_d <= 0 && cd_a * cd_b <= 0;
}


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
        return child[x];
    } else{
        group[x] = y;
        child[y] += child[x];
        return child[y];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    lines.resize(N);
    group.resize(N);
    child.resize(N);
    for(int i=0; i<N; i++) group[i] = i;
    for(int i=0; i<N; i++) child[i] = 1;
    for(auto &[p1, p2] : lines){
        cin >> p1.first >> p1.second >> p2.first >> p2.second;
    }

    int cnt = N, maxLine = 1;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(group[i]==group[j]) continue;
            if(cross(lines[i], lines[j])){  
                int childCnt = merge(i, j);
                if(childCnt){
                    maxLine = max(maxLine, childCnt);
                    cnt--;
                }
            }
        }
    }

    cout << cnt << '\n' << maxLine;
    return 0;
}