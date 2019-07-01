#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //摩尔投票法
        int candiNum1(0),candiNum2(0),vote1(0),vote2(0);
        int len = nums.size();
        for(auto iter=nums.begin();iter!=nums.end();++iter)
        {
            if(*iter == candiNum1 )
            {
                ++vote1;
            }
            else if(*iter == candiNum2)
            {
                ++vote2;
            }
            else if(vote1==0)
            {
                candiNum1 = *iter;
                vote1=1;
            }
            else if(vote2==0)
            {
                candiNum2 = *iter;
                vote2 = 1;
            }
            else {
                --vote1;
                --vote2;
            }   
        }
        int curNum1(0),curNum2(0);
        for(auto iter = nums.begin();iter!=nums.end();++iter)
        {
            if(*iter == candiNum1){
                ++curNum1;
            }
            else if(*iter == candiNum2){
                ++curNum2;
            }
        }
        vector<int > res;
        if(curNum1>len/3){
            res.push_back(candiNum1);
        }
        if(curNum2>len/3)
        {
            res.push_back(candiNum2);
        }
        return res;
    }
};

