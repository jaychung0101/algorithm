// 출근 기록
#include <iostream>
#include <vector>
using namespace std;

int worker[3];
bool DP[51][51][51][3][3];
char current[50];

bool solve(int a, int b, int c, int pp, int p){
    if (a==worker[0] && b==worker[1] && c==worker[2]) return 1;

    if(DP[a][b][c][pp][p]) return 0;
    else DP[a][b][c][pp][p] = 1;

    if(a+1 <= worker[0]) {
		current[a+b+c] = 'A';
		if(solve(a+1, b, c, p, 0))
			return true;
	}
	if(b+1 <= worker[1]) {
		current[a+b+c] = 'B';
		if(p!=1 && solve(a, b+1, c, p, 1))
			return true;
	}
	if(c+1 <= worker[2]) {
		current[a+b+c] = 'C';
		if(pp!=2 && p!=2 && solve(a, b, c+1, p, 2))
			return true;
	}
	return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    for(char x : s){
        if(x=='A') worker[0]++;
        else if(x=='B') worker[1]++;
        else worker[2]++;
    }

    if(solve(0, 0, 0, -1, -1)) for(char x : current) cout << x;
    else cout << -1;
    
    cout << '\n';
    return 0;
}