//LCS
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int columnMax = s1.size();
    int rowMax = s2.size();
    vector<vector<int>> v(rowMax+1, vector<int>(columnMax+1, 0));
    for(int i=1; i<=rowMax; i++){
        for(int j=1; j<=columnMax; j++){
            v[i][j] = (s2[i-1]==s1[j-1] ? v[i-1][j-1] + 1 : max(v[i-1][j], v[i][j-1]));
        }
    }

    cout << v[rowMax][columnMax];

    return 0;
}