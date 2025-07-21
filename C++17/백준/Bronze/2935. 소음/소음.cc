#include <iostream>
using namespace std;

int main(){
    string a, b, c; cin >> a >> b >> c;
    string answer;
    if(b=="+"){
        if(a.size()>c.size()){
            answer = a;
            answer[a.size()-c.size()] = '1';
        } else if(a.size()<c.size()){
            answer = c;
            answer[c.size()-a.size()] = '1';
        } else{
            answer = a;
            answer[0] = '2';
        }

        cout << answer;
    } else{
        cout << '1';
        for(int i=0; i<a.size()+c.size()-2; i++) cout << '0';
    }
}