#include <iostream>
void Partition(int a[],int p,int r)
{
    int i = r+1;
    for(int j = r;j>=p;--j)
    {
        if(a[j]!=0)
        {
            --i;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}
int main()
{
    int a[7] = {0,3,0,2,1,0,0};
    Partition(a,0,6);
    for(int idx = 0;idx<7;++idx)
    {
        std::cout<<idx<<" ";
    }
    std::cout<<std::endl;
    return 0;
}

