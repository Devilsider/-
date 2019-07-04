#include <iostream>
using namespace std;
int add(int num,...)
{
    int sum = 0;
    int index =0;
    int *p =(int *) &num+1;
    
    for(;index<num;++index)
    {
        sum += *p++;
    }
    return sum;
}
int main()
{
    int i=1,j=2,k=3;

    cout<<add(3,i,j,k);
   
    return 0;
}

