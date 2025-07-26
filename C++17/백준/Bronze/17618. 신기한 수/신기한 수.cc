#include <iostream>
using namespace std;

int main(){
    int N; cin >> N;
    
    int answer = 0;
    for(int i=1; i<=N; i++){
        int temp = i;
        int x=0;
        while(temp){
            x += temp%10;
            temp /= 10;
        }
        
        if(i%x==0) answer++;
    }
    
    cout << answer;
}