// 체스판 다시 칠하기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> comp(n, vector<char>(m, 'B'));
    for(int i=0; i<n; i=i+2){
        for(int j=1; j<m; j=j+2)
            comp[i][j] = 'W';
    }

    for(int i=1; i<n; i=i+2){
        for(int j=0; j<m; j=j+2)
            comp[i][j] = 'W';
    }

    vector<vector<char>> v(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;
            v[i].push_back(c);
        }
    }

    vector<vector<int>> cnt(n);
    for(int i=0; i<n; i++){
        queue<bool> q;
        int sum = 0;
        for(int j=0; j<8; j++){
            if(v[i][j]!=comp[i][j]){
                q.push(true);
                sum++;
            }
            else
                q.push(false);
        }

        cnt[i].push_back(sum);
        for(int j=8; j<m; j++){
            if(q.front()) sum--;
            q.pop();

            if(v[i][j]!=comp[i][j]){
                q.push(true);
                sum++;
            }
            else
                q.push(false);
            cnt[i].push_back(sum);
        }
    }

    vector<int> res;
    for(int j=0; j<m-7; j++){
        queue<int> q2;
        int sum = 0;
        for(int i=0; i<8; i++){
            sum += cnt[i][j];
            q2.push(cnt[i][j]);
        }
        
        res.push_back(min(sum, 64-sum));
        for(int i=8; i<n; i++){
            sum -= q2.front();
            q2.pop();
            sum += cnt[i][j];
            q2.push(cnt[i][j]);
            res.push_back(min(sum, 64-sum));
        }
    }
    
    sort(res.begin(), res.end());
    cout << res[0];
    return 0;
}