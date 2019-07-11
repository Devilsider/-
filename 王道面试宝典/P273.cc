#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class MyBinarySearch
{
public:
    int binarySearch(vector<T> &arr,T key)
    {
        int len = static_cast<int>(arr.size());
        int left = 0,right = len ;
        int mid;
        while(left<right)
        {
            mid = (left+right)/2;
            if(arr[mid]==key)
            {
                return mid;
            }
            else if(arr[mid]<key)
            {
                left= mid+1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,89,100} ;

    MyBinarySearch<int> bs;
    int ret = bs.binarySearch(arr,4);
    cout<<ret<<endl;
    return 0;
}

