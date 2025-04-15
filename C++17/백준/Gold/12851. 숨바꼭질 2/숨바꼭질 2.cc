// 숨바꼭질 2
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int answerTime, answerCnt;

void dijkstra(vector<int> &used, int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    used[start] = 0;
    pq.push({0, start});

    while(true){
        int cT = pq.top().first;
        int cV = pq.top().second; pq.pop();

        if(cV==k){
            answerTime = cT;
            answerCnt = 1;
            while(!pq.empty() && pq.top().first==cT){
                if(pq.top().second==cV) answerCnt++;
                pq.pop();
            }
            break;
        }

        if(used[cV]<cT) continue;
        used[cV] = cT;

        int dx[3] = {-1, 1, cV};
        for(int i=0; i<3; i++){
            int nx = cV+dx[i];
            if(nx<0 || nx>=2*(k+1)) continue;
            pq.push({cT+1, cV+dx[i]});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if(k<n){
        cout << n-k << '\n' << 1;
    } else{
        vector<int> used(2*(k+1), INT32_MAX);
        dijkstra(used, n);
        
        cout << answerTime << '\n' << answerCnt;
    }

    return 0;
}