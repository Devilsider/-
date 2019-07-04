#include <iostream>
using namespace std;
int main()
{
    int a =3;
    a += (a++);
    cout<<a<<endl;
    a += (++a);
    cout<<a<<endl;
    (++a) += (a++);
    cout<<a<<endl;
    return 0;
}

