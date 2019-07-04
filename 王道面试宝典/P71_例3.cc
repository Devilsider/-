#include <iostream>

int updateBits(int n,int m,int i,int j)
{
    int max = ~0;
    int left = max - ((1<<j)-1);
    int right = ((1<<i)-1);
    int mask = left|right;
    return (n&mask)|(m<<i);
}

int main()
{
    int n = 1024 ;
    int m =21;

    int  res = updateBits(n,m,2,6);
    std::cout<<res<<std::endl;
    return 0;
}

