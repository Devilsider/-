#include <iostream>
#include <vector>
using namespace std;

int Partion(vector<int> arr,int low,int high)
{
    //快排一次
    int pivot = arr[low];
    int start = low;
    while(low<high)
    {
        while(low<high&&arr[high]>=pivot)
        {
            --high;
        }
        while(low<high&&arr[low]<=pivot)
        {
            ++low;
        }
        if(low<high){
            swap(arr[high],arr[low]);
        }
    }
    arr[start] = arr[low];
    arr[low] = pivot;
    return low;
}
vector<int> getLeastKNum(vector<int> &input,int n,int k)
{
    if(input.empty()||k>n||n<=0||k<=0)
    {
        vector<int> empty;
        return empty;
    }
    int start = 0;
    int end = n-1;
    int index = Partion(input,start,end);

    while(index != k-1)
    {
        if(index>k-1)
        {
            end =index -1;
            index = Partion(input,start,end);
        }
        else {
            start = index +1;
            index =Partion(input,start,end);
        }
    }
    vector<int> output;
    for(int idx =0;idx<k;++idx)
    {
        output.push_back(input[idx]);
    }
    return output;
}
int main()
{
    vector<int> input = {1,2,3,4,5,6,7,8,98} ;
    vector<int> output;
    output = getLeastKNum(input,input.size()-1,4);

    for(auto &i:output)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}

