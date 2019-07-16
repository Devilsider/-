#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr(10) ;
    for(int idx =0;idx<10;++idx)
    {
        arr.push_back(idx);
    }

    cout<<"now "<<arr.capacity()<<endl;
    arr.clear();
    cout<<"clear "<<arr.capacity()<<endl;
    arr.shrink_to_fit();
    cout<<"shrink_to_fit "<<arr.capacity()<<endl;

    return 0;
}

