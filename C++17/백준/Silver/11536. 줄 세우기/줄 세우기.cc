// 줄 세우기
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    string prev; cin >> prev;
    string next; cin >> next;

    bool flag;
    if(prev > next) flag = true;
    else flag = false;

    bool neither = false;
    for(int i=2; i<N; i++){
        prev = next;
        cin >> next;
        if(flag){
            if(prev < next){
                neither = true;
            }
        }
        else{
            if(prev > next){
                neither = true;
            }
        }
    }

    if(neither){
        cout << "NEITHER";
    }
    else{
        if(!flag) cout << "INCREASING";
        else cout << "DECREASING";
    }
}