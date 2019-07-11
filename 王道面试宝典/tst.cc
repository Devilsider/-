#include <iostream>
#include <vector>
using namespace std;
void shellSort(vector<int> &arr)
{
    int i,j,gap;
    int len = static_cast<int>(arr.size());

    for(gap = len>>1;gap>0;gap>>=1)
    {
        for(i = gap;i<len;++i)
        {
            int temp  =  arr[i];
            for(j = i-gap;j>=0&&arr[j]>temp;j-=gap)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
    }
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

