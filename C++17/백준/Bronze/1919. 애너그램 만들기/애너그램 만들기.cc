//애너그램 만들기
#include <iostream>
#include <vector>
using namespace std;

vector<int> v(26);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string A, B; cin >> A >> B;
    for(char x : A) v[x-'a']++;
    for(char x : B) v[x-'a']--;

    int answer = 0;
    for(int x : v) answer += abs(x);
    cout << answer;
    
    return 0;
}