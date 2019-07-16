#include <iostream>
using namespace std;

int FiveCount(int n)
{
    int i,j,sum = 0 ;
    for(i=1;i<=n;++i)
    {
        j = i;
        while(j%5==0)
        {
            j = j/5;
            ++sum;
        }
    }
    return sum;
}
int fivecount(int n )
{
    if(n<0)
    {
        return -1;
    }
    int i,j,count=0;
    for(i =1;i<=n;++i)
    {
        j = i;
        while(j%5==0)
        {
            j=j/5;
            ++count;
        }
    }
    return count;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

