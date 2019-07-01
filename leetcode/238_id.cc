#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    //遍历方式
    vector<int> productExceptSelf(vector<int>& nums) {
        if(0==nums.size()||1==nums.size())
        {
            return nums;
        }
        vector<int> res(nums.size());
        res[0]=1;
        int len =nums.size();
        for(int idx = 1;idx<len;++idx)
        {
            res[idx]= res[idx-1]*nums[idx-1];
        }
        for(auto &i:res)
        {
            cout<<i<<endl;
        }
        int temp=1;
        for(int idx = len-2;idx>0;--idx)
        {
            temp *=nums[idx+1];
            res[idx]=res[idx]*temp;
        }
        res[0] = res[0]*temp*nums[1];
        cout<<"----------------"<<endl;
        for(auto &i:res)
        {
            cout<<i<<endl;
        }    
        return res;
    }
};

