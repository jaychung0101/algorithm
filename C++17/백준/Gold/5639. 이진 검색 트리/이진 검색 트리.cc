//이진 검색 트리
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> key(1000001, {-1, -1});
int root;

void makeTree(){
    int num; cin >> num;
    root = num; 

    while(cin >> num){
        int current = root;
        while(true){
            if(num<current){
                if(key[current].first==-1){
                    key[current].first = num;
                    break;
                }
                current = key[current].first;
            } else{
                if(key[current].second==-1){
                    key[current].second = num;
                    break;
                }
                current = key[current].second;
            }
        }
    }
}

void postOrder(int current){
    if(current==-1) return;

    postOrder(key[current].first);
    postOrder(key[current].second);
    cout << current << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    makeTree();
    postOrder(root);    
}
