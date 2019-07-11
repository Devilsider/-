#include <iostream>
#include <vector>
using namespace std;
void RedWhiteBlue(vector<int> &arr)
{
    int len = static_cast<int>(arr.size());

    int begin = 0;
    int end = len -1;
    int current = begin;

    while(current<= end)
    {
        if(1==arr[current])
        {
           ++current; 
        }
        else if(0==arr[current])
        {
            swap(arr[begin++],arr[current++]);
        }
        else if(2==arr[current])
        {
            swap(arr[current],arr[end--]);
        }
    }
}
int main()
{
    vector<int> nationalFlag = {0,1,2,1,1,2,0,2,1,0,0,0,0,1,1,1,1,2,2,2};
    RedWhiteBlue(nationalFlag);

    for(auto &i:nationalFlag)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

