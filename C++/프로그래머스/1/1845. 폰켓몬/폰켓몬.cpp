#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    
    int idx = 0;
    int answer = 0;
    int pre = -1;
    while(idx<nums.size()){
        if(nums[idx]!=pre){
            answer++;
            if(answer==nums.size()/2){
                break;
            }
            pre = nums[idx];
        }
        idx++;
    }
    return answer;
}