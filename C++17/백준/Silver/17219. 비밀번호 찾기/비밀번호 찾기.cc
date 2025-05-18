//비밀번호 찾기
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    unordered_map<string, string> m;
    while(N--){
        string site, pass; cin >> site >> pass;
        m[site] = pass;
    }

    while(M--){
        string site; cin >> site;
        cout << m[site] << '\n';
    }

    return 0;
}