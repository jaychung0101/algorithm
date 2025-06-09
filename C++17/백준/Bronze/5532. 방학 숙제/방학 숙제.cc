#include <iostream>
using namespace std;

int main(){
    int L, A, B, C, D; cin >> L >> A >> B >> C >> D;
    int answer1=0, answer2=0;
    
    answer1 += A/C;
    if(A%C) answer1++;
    
    answer2 += B/D;
    if(B%D) answer2++;
    
    cout << L - max(answer1, answer2);
    
    return 0;
}