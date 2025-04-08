// 치킨 배달
#include <iostream>
#include <vector>
using namespace std;

int N, M, answer = INT32_MAX; 
vector<pair<int, int>> chickens, homes;
vector<vector<int>> dist;
vector<bool> used;

void backTracking(int idx, int cnt){
    if(idx>chickens.size()) return;
    if(cnt==M){
        vector<int> answer_dist(homes.size(), INT32_MAX);
        for(int i=0; i<chickens.size(); i++){
            if(used[i]){
                for(int j=0; j<homes.size(); j++){
                    answer_dist[j] = min(answer_dist[j], dist[i][j]);
                }
            }
        }

        int temp = 0;
        for(int x : answer_dist) temp += x;
        answer = min(answer, temp);
        return;
    }

    used[idx] = true;
    backTracking(idx+1, cnt+1);
    used[idx] = false;
    backTracking(idx+1, cnt);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int num; cin >> num;
            if(!num) continue;
            
            if(num==1){
                homes.push_back({i, j});
            } else if(num==2){
                chickens.push_back({i, j});
            }
        }
    }

    used.resize(chickens.size());
    dist.resize(chickens.size(), vector<int>(homes.size()));

    for(int i=0; i<chickens.size(); i++){
        for(int j=0; j<homes.size(); j++){
            dist[i][j] = 
            abs(chickens[i].first-homes[j].first) +
            abs(chickens[i].second-homes[j].second);
        }
    }

    backTracking(0, 0);

    cout << answer;

    return 0;
}