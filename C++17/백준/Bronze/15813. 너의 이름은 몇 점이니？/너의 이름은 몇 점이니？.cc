#include <iostream>
using namespace std;
 
int main(){
    int len; cin >> len;
    string name; cin >> name;
    
    int score = 0;
    for(char c : name){
        score += c - 'A' + 1;    
    }
    
    cout << score;
    
    return 0;
}