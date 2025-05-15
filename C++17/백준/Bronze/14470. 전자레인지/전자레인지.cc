//전자레인지
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int A, B, C, D, E; cin >> A >> B >> C >> D >> E;

    int answer = 0;
    if(A<0){
        answer += abs(A)*C;
        A=0;
    }

    if(A==0){
        answer += D;
    }

    answer += (B-A)*E;

    cout << answer;
    
    return 0;
}