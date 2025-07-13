#include <iostream>
using namespace std;

int main() {
    int people[4];
    for(int &person : people) cin >> person;
    
    int x, y, r; cin >> x >> y >> r;
    
    int answer = 0;
    for(int i=0; i<4; i++){
      if(people[i]==x){
        answer = i+1;
        break;
      }
    }
    
    cout << answer;
    
    return 0;
}