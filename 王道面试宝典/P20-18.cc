#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> find(const vector<int> &nums)
    {
        if(nums.size()<3)
        {
            return nums;
        }
        vector<int> rightMin(nums.size());
        int len =nums.size();
        rightMin[len-1]=nums[len-1];
        for(int idx=len-2;idx>=0;--idx)
        {
            if(nums[idx]<rightMin[idx+1])
            {
                rightMin[idx] = nums[idx];
            }
            else {
                rightMin[idx] = rightMin[idx+1];
            }
        }
        vector<int> res;
        int max=*nums.begin();
        for(int idx = 1 ;idx<len;++idx)
        {
            if(nums[idx]>=max)
            {
                max = nums[idx];
                if(max == rightMin[idx]){
                    res.push_back(max);
                }
            }
        }
        return res;
    }
};

