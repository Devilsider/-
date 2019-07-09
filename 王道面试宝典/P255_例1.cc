#include <iostream>
bool isUpper(char a)
{
    if(a>='A' && a<='Z')
    {
        return true;
    }
    return false;
}
bool isLower(char a)
{
    if(a>='a' && a<='z')
    {
        return true;
    }
     return false;
}
void Partition(char a[],int low,int high)
{
    while(low<high)
    {
        while(low<high && isUpper(a[high]))--high;
        while(low<high && isLower(a[low]))++low;
        char temp = a[high];
        a[high] = a[low];
        a[low] = temp;
    }
}
int main()
{
    char a[7] = {'a','A','Z','d','B','s','b'};
    Partition(a,0,6);
    for(int idx = 0;idx<7;++idx)
    {
        std::cout<<a[idx]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}

