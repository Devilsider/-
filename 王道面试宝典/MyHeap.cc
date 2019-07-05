#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyHeap
{
public:
    void maxHeapify(vector<T> &arr,int start,int end)
    {
        cout<<"1111"<<endl;
        int dad =start,son = dad*2+1;
        while(son<=end)
        {
            if(son+1<=end&&arr[son]<arr[son+1])
            {
                ++son;
            }
            if(arr[son]<arr[dad])
            {
                return ;
            }
            else 
            {
                swap(arr[dad],arr[son]);
                dad = son;
                son = dad *2 +1;
            }
        }
    }
    void heapSort(vector<T> &arr)
    {
        int len = (int)arr.size();
        for(int idx = len/2-1;idx>=0;--idx)
        {
            maxHeapify(arr,idx,len-1);
        }
        for(int idx = len - 1;idx>0;--idx)
        {
            swap(arr[0],arr[idx]);
            maxHeapify(arr,0,idx-1);
        }
    }
};
int main()
{
    vector<int> arr = {2,3,1,232,43252,2234324,3245};
    MyHeap<int> myheap;
    myheap.heapSort(arr);
    for(auto &i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

