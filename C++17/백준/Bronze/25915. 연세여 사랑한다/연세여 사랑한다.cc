#include <iostream>
using namespace std;

int main(){
    char current; cin >> current;
    string s = "ILOVEYONSEI";

    int sum = 0;
    for(char c : s){
        sum += abs(int(current-c));
        current = c;
    }

    cout << sum;

    return 0;
}