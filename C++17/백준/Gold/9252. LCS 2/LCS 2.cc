//LCS 2
#include <iostream>
#include <vector>
using namespace std;

string differ(string a, string b){
    if(a.size()>b.size()) return a;
    return b;
}

string equalChar(string a, string b, char c){
    if(a.size()+1>=b.size()) return a+c;
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string A, B; cin >> A >> B;
    vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));

    for(int row=1; row<A.size()+1; row++){
        for(int column=1; column<B.size()+1; column++){
            if(A[row-1]==B[column-1]){
                dp[row][column] = dp[row-1][column-1] + 1;
            } else{
                dp[row][column] = max(dp[row][column-1], dp[row-1][column]);
            }
        }
    }

    string lcs = "";
    int r = A.size(), c = B.size();
    while(r>0 && c>0){
        if(A[r-1]==B[c-1]){
            lcs = A[r-1] + lcs;
            r--; c--;
        } else if(dp[r-1][c] >= dp[r][c-1]){
            r--;
        } else{
            c--;
        }
    }

    cout << dp[A.size()][B.size()] << '\n';
    if(lcs.size()>0) cout << lcs << '\n';

    return 0;
}