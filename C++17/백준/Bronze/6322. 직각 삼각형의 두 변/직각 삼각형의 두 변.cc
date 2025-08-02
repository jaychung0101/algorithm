#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int i = 1;

    cout << fixed;
    cout.precision(3);

    while(true){
        int a, b, c; cin >> a >> b >> c;
        
        if(a==0 && b==0 && c==0){
            break;
        }
        
        cout << "Triangle #" << i++ << '\n';
        double answer;
        if(a==-1 && b<c){
            answer = sqrt(c*c-b*b);
            cout << "a = " << answer;
        } else if(b==-1 && a<c) {
            answer = sqrt(c*c-a*a);
            cout << "b = " << answer;
        } else if(c==-1) {
            answer = sqrt(a*a+b*b);
            cout << "c = " << answer;
        } else {
            cout << "Impossible.";
        }
        
        cout << "\n\n";
    }
    return 0;
}
