//팩토리얼 0의 개수
#include <iostream>
using namespace std;

int main(){
    int N; cin >> N;

    int cnt2 = 0, cnt5 = 0;
    for(int i=2; i<=N; i++){
        int temp = i;
        while(temp%2==0){
            cnt2++;
            temp /= 2;
        }

        while(temp%5==0){
            cnt5++;
            temp /= 5;
        }
    }

    cout << min(cnt2, cnt5);

    return 0;
}