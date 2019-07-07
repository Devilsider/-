#include <iostream>
using  namespace std;
class A{};
class B
{
public:
    B();
    virtual ~B();
};
class C
{
private:
#pragma pack(4)
    int i;
    short j;
    float k;
    char l[64];
    long m;
    char *p;
#pragma pack()
};
class D
{
private:
#pragma pack(1)
    int i;
    short j;
    float k;
    char l[64];
    long m;
    char *p;
#pragma pack()
};
int main()
{
    cout<<"A = "<<sizeof(A)<<endl;
    cout<<"B = "<<sizeof(B)<<endl;
    cout<<"C = "<<sizeof(C)<<endl;
    cout<<"D = "<<sizeof(D)<<endl;
    return 0;
}

