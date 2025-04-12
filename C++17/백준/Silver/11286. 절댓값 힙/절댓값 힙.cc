// 절댓값 힙
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int> n;
    priority_queue<int, vector<int>, greater<int>> p;

    int N; cin >> N;
    for(int i=0; i<N; i++){
        int x; cin >> x;
        if(x>0) p.push(x);
        else if(x<0) n.push(x);
        else{
            if(!p.empty() && !n.empty()){
                if(p.top()<-n.top()){
                    cout << p.top(); p.pop();
                }
                else{
                    cout << n.top(); n.pop();
                }
            }
            else if(p.empty() && !n.empty()){
                cout << n.top(); n.pop();
            }
            else if(!p.empty() && n.empty()){
                cout << p.top(); p.pop();
            }
            else cout << 0;
            
            cout << '\n';
        }
    }

    return 0;
}