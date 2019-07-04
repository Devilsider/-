#include <iostream>
using namespace std;

int main()
{
    int n =128;
    if(n>1&&(n&(n-1))==0)
    {
        cout<<"yes"<<endl;
    }
    return 0;
}

