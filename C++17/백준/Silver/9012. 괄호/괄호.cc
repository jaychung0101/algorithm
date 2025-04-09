// 괄호
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int sum = 0;
        bool flag = true;
        string p;
        cin >> p;

        for(char c : p){
            if(c=='(') sum++;
            else if(sum==0) flag=false;
            else sum--;
        }
        if(sum>0) flag=false;

        cout << (flag ? "YES" : "NO") << '\n';
    }
}