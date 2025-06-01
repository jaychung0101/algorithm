#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int M; cin >> M;
        char C; cin >> C;

        if(C=='C'){
            vector<char> v(M);
            for(char &x : v){
                cin >> x;
            }

            for(char x : v){
                cout << int(x-'A'+1) << ' ';
            }
        } else{
            vector<int> v(M);
            for(int &x : v){
                cin >> x;
            }

            for(int x : v){
                cout << char(x+'A'-1) << ' ';
            }
        }
        
        cout << '\n';
    }
    
    return 0;
}