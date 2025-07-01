//벽 부수고 이동하기 4
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <set>
using namespace std;

int N, M; 
int cluster = 1;

vector<vector<char>> map;
vector<vector<pair<int, int>>> tempMap;
vector<vector<int>> answer;
vector<vector<bool>> used;

int dr[4] = {1, -1, 0, 0};
int dl[4] = {0, 0, 1, -1};

void marking(int r, int l){
    queue<pair<int, int>> q;
    deque<pair<int, int>> d;
    q.emplace(r, l);

    int count = 0;
    while(!q.empty()){
        auto [cr, cl] = q.front(); q.pop();
        
        if(used[cr][cl]) continue;
        used[cr][cl] = true;

        d.emplace_back(cr, cl);
        count++;

        for(int i=0; i<4; i++){
            int nr = cr+dr[i];
            int nl = cl+dl[i];

            if(nr<0 || nr>=N || nl<0 || nl>=M || map[nr][nl]=='1' || used[nr][nl]) continue;

            q.emplace(nr, nl);
        }
    }

    for(auto [cr, cl] : d){
        tempMap[cr][cl].first = cluster;
        tempMap[cr][cl].second = count;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    map.resize(N, vector<char>(M));
    tempMap.resize(N, vector<pair<int, int>>(M, {0, 0}));
    answer.resize(N, vector<int>(M, 0));
    used.resize(N, vector<bool>(M, false));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]=='0' && !used[i][j]){
                marking(i, j);
                cluster++;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]=='1'){
                int temp = 1;
                set<int> clusters;

                for(int k=0; k<4; k++){
                    int nr = i+dr[k];
                    int nl = j+dl[k];

                    if(nr<0 || nr>=N || nl<0 || nl>=M || clusters.count(tempMap[nr][nl].first)) continue;
                    clusters.insert(tempMap[nr][nl].first);
                    temp += tempMap[nr][nl].second;
                }

                answer[i][j] = temp%10;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << answer[i][j];
        }
        cout << '\n';
    }

    return 0;
}