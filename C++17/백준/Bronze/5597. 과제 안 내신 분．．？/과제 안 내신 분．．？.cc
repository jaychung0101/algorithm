// 과제 안 내신 분..?
#include <iostream>
using namespace std;

int main() {
    bool arr[30]={false};
    for (int i=0; i<28; i++) {
        int I;
        cin >> I;
        arr[I-1]=true;
    }

    for (int i=0; i<30; i++) {
        if(arr[i]==false) cout << i+1 << '\n';
    }
}