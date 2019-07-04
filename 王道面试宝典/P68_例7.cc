#include <iostream>
using namespace std;

int add_no_arithm(int a,int b)
{
    if(b==0)return a;
    int sum =a^b;
    int carry= (a&b)<<1;
    return add_no_arithm(sum,carry);
}

int add_no_artithm_noRecursive(int a,int b )
{
    int sum = a^b;
    int carry = a&b;
    while(carry)
    {
        int tmpSum = sum;
        int tmpCarry = carry<<1;
        sum = tmpSum^tmpCarry;
        carry = tmpSum&tmpCarry;

    }
    return sum;
}

int main()
{
    int a = 4 ,b=5;
    int res1,res2;


    res1 = add_no_artithm_noRecursive(a,b);
    cout<<res1<<endl;
    res2 = add_no_arithm(a,b);
    cout<<res2<<endl;
    return 0;
}

