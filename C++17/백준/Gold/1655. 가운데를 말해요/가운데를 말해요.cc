// 가운데를 말해요
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> b;
    
    int mid, dif=0; cin >> mid;
    cout << mid << '\n';
    for(int i=1; i<N; i++){
        int x; cin >> x;
        if(x>=mid){
            b.push(x);
            dif++;
            
            if(dif==2){
                s.push(mid);
                mid = b.top();
                b.pop();
                dif-=2;
            }
        }
        else{
            s.push(x);
            dif--;
            
            if(dif==-1){
                b.push(mid);
                mid = s.top();
                s.pop();
                dif+=2;
            }
        }

        cout << mid << '\n';
    }
    return 0;
}