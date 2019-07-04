#include <iostream>
int swapOddEvenBits(int x)
{
    return (((x&0xaaaaaaaa)>>1)|((x&0x55555555)<<1));
}

int main()
{
    int x = 235;
    int res = swapOddEvenBits(x);
    std::cout<<res<<std::endl;

    return 0;
}

