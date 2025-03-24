// 트리 순회
#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, char>> tree;

void preorder(int current){
    cout << char(current+'A');

    int left = tree[current].first-'A';
    int right = tree[current].second-'A';
    
    if(0<=left && left<=25) preorder(left);
    if(0<=right && right<=25) preorder(right);
}

void inorder(int current){
    int left = tree[current].first-'A';
    int right = tree[current].second-'A';
    
    if(0<=left && left<=25) inorder(left);
    cout << char(current+'A');
    if(0<=right && right<=25) inorder(right);
}

void postorder(int current){
    int left = tree[current].first-'A';
    int right = tree[current].second-'A';
    
    if(0<=left && left<=25) postorder(left);
    if(0<=right && right<=25) postorder(right);
    cout << char(current+'A');
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    tree.resize(N);
    for(int i=0; i<N; i++){
        char parent; cin >> parent;
        char left, right; cin >> left >> right;
        tree[parent-'A'] = {left, right};
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    
    return 0;
}   