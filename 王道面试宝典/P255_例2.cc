#include <iostream>
#include <vector>
using namespace std;

void Partion(vector<int> &arr,int start,int end)
{
    int i = end+1;
    for(int j=end;j>=start;--j)
    {
        if(arr[j]!=0)
        {
            --i;
            swap(arr[i],arr[j]);
        }
    }
}
int main(void)
{
    vector<int> arr = {0,3,0,2,1,0,0};
    Partion(arr,0,6);

    for(auto &i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
