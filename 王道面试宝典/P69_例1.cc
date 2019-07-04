#include <iostream>

int func(int n)
{
    //统计1的个数
    int count = 0;
    while(n!=0)
    {
        n &= (n-1);
        ++count;
    }
    return  count;
}


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

