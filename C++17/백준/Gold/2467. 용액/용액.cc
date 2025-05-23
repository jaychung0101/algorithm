    //용액
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> n, p;
    for(int i=0; i<N; i++){
        int x; cin >> x;
        if(x<0) n.push_back(x);
        else p.push_back(x);
    }

    int density = INT32_MAX;
    int l = 0, r = p.size()-1;
    int a1, a2;

    if(!n.empty() && !p.empty()){
        while(l<n.size()-1 || r>0){
            int temp = abs(n[l] + p[r]);
    
            if(temp<density){
                density = temp;
                a1 = n[l];
                a2 = p[r];
            }
    
            if(density==0) break;
    
            if(abs(n[l])>abs(p[r])){
                if(l==n.size()-1){
                    r--;
                } else{
                    l++;
                }
            } else if(abs(n[l])<=abs(p[r])){
                if(r==0){
                    l++;
                } else{
                    r--;
                }
            }
        }
    }

    if(n.size()>=2){
        int t1 = n[n.size()-1];
        int t2 = n[n.size()-2];

        if(abs(t1+t2) <= density){
            density = abs(t1+t2);
            a1 = t1;
            a2 = t2;
        }
    }

    if(p.size()>=2){
        int t1 = p[0];
        int t2 = p[1];

        if(abs(t1+t2) <= density){
            density = abs(t1+t2);
            a1 = t1;
            a2 = t2;
        }
    }

    cout << min(a1, a2) << ' ' << max(a1, a2);

    return 0;
}