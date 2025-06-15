//세 용액
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int N; cin >> N;
    vector<long long> v(N);
    for(long long &x : v) cin >> x;

    sort(v.begin(), v.end());
    long long d1, d2, d3;
    if(v[N-1]<=0){
        d1 = v[N-3];
        d2 = v[N-2];
        d3 = v[N-1];
    } else if(v[0]>=0){
        d1 = v[0];
        d2 = v[1];
        d3 = v[2];
    } else{
        long long answer = LLONG_MAX;
        for(int i=0; i<N-2; i++){
            long long value = v[i];
            for(int j=i+1; j<N-1; j++){
                long long temp = value + v[j];
                auto it = lower_bound(v.begin()+j+1, v.end(), -temp);

                if(it==v.end()){
                    if(abs(temp+v[N-1])<answer){
                        answer = abs(temp+v[N-1]);
                        d1 = v[i];
                        d2 = v[j];
                        d3 = v[N-1];
                    }
                } else{
                    if(*it==-temp){
                        d1 = v[i];
                        d2 = v[j];
                        d3 = *it;          
                        break;              
                    } else{
                        if(abs(temp+*it)<answer){
                            answer = abs(temp+*it);
                            d1 = v[i];
                            d2 = v[j];
                            d3 = *it;
                        }
                        if(it>v.begin()+j+1){
                            if(abs(temp+*(it-1))<answer){
                                answer = abs(temp+*(it-1));
                                d1 = v[i];
                                d2 = v[j];
                                d3 = *(it-1);
                            }
                        }
                    }
                }
            }

            if(answer==0) break;
        }
    }
    cout << d1 << ' ' << d2 << ' ' << d3;
    return 0;
}