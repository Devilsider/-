#include <iostream>
using namespace std;

int getMaxSum(int a[],int length)
{
    int sum =0;
    int maxSum = 0;
    for(int idx = 0;idx<length;++idx)
    {
        sum += a[idx];
        if(maxSum<sum)
        {
            maxSum = sum;
        }else if(sum<0)
        {
            sum = 0;
        }
    }
    return maxSum;
}



