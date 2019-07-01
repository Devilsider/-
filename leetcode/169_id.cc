#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curNum,curCount;
        curNum = nums[0];
        curCount = 0;
        for(auto iter = nums.begin();iter!=nums.end();++iter)
        {
            if(curCount == 0)
            {
                curNum = *iter;
                curCount = 1;
            }
            else {
                if(curNum == *iter)
                {
                    ++curCount;
                }
                else {
                    --curCount;
                }
            }
        }
        return curNum;
    }
};
