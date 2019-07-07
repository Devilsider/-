#include <iostream>
#include <vector>
using namespace std;

class BackPack
{
public:
    int MaxWeight(vector<int> &weight,vector<int> &value,int capacity) 
    {
        if(weight.size()!=value.size())
        {
            //数据输入错误
            return -1;
        }
        int len1 = static_cast<int>(weight.size());
        int len2 = capacity+1;

        int matrix[len1][len2];

        for(int idx = 0;idx<len2;++idx)
        {
            //初始化
            matrix[0][idx]=0;
        }
        for(int idx = 0;idx<len1;++idx)
        {
            matrix[idx][0]=0;
        }

        for(int i = 1;i<len1;++i)
        {//动态规划，使用状态转移方程
            for(int j =1;j<len2;++j)
            {
                if(j<weight[i])
                {
                    matrix[i][j] = matrix[i-1][j];
                }else{
                    matrix[i][j] =
                    matrix[i-1][j]>(matrix[i-1][j-weight[i]]+value[i])?matrix[i-1][j]:(matrix[i-1][j-weight[i]]+value[i]);
                }
            }
        }
        for(int i=0;i<len1;++i)
        {
            for(int j=0;j<len2;++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

        return matrix[len1-1][len2-1];
        
    }
};

int main()
{
    vector<int> c = {0,1,2,3};
    vector<int> w = {0,60,100,120};
    
    BackPack bpack;

    int res = bpack.MaxWeight(c,w,5);

    cout<<res<<endl;
    
    return 0;
}

