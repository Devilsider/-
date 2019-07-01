#include "P20-18.cc"

#include <iostream>

int main()
{
    vector<int> array= {7,10,2,6,19,22,32};

    Solution s;
    auto res = s.find(array);
    for(auto &i : res){
        cout<<i<<endl;
    }

    return 0;
}

