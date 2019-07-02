#include <iostream>
using namespace std;
int main()
{
    int a[4][5];
    int (*p)[5];
    p = a;

    cout<<"&a[2][3]= "<<&a[2][3]<<endl;
    cout<<"(*(p+2)+3)= "<<(*(p+2)+3)<<endl;
    cout<<"*(p+13)= "<<*(p+13)<<endl;

    return 0;
}

