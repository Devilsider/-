#include <iostream>

using namespace std;

bool isUpper(char a)
{
    if(a>='A'&&a<='Z')
    {
        return true;
    }
    return false;
}
bool isLower(char a)
{
    if(a>='a'&&a<='z')
    {
        return true;
    }
    return false;
}
void Partion(char arr[],int low,int high)
{
    //快排一次排序的基本实现
    while(low<high)
    {
        while(low<high&&isUpper(arr[high]))
        {
            --high;
        }
        while(low<high&&isLower(arr[low]))
        {
            ++low;
        }
        swap(arr[high],arr[low]);
    }
}
int main()
{
    char a[] = {'a','A','Z','d','B','s','b'};
    Partion(a,0,6);

    for(int idx = 0;idx < 7;++idx)
    {
        cout<<a[idx]<<" ";
    }
    cout<<endl;

    return 0;
}

