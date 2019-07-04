#include <iostream>

int add(int a,int b)
{
    int sum = a^b;
    int carry = a&b;
    while(carry)
    {
        int tmpSum = sum ^ carry;
        int tmpCarry = carry <<1;

        sum = tmpSum ^ tmpCarry;
        carry = tmpSum & tmpCarry;
        
    }
    return sum;
}
int negative(int a)
{
    //取补码
    //实现减法
    return add(~a,1);
}
int sub(int a,int b)
{
    return add(a,negative(b));
}
int multiply(int a,int b)
{
    int res = 0;
    while(b)
    {
        if(b&1)
        {
            res = add(res,a);
        }
        a = a<<1;
        b = b>>1;
    }
    return res;
}
int divide(int a,int b )
{
    int res =0; 
    for(int idx = 31; idx >= 0;--idx)
    {
        if((a>>idx)>b)
        {
            res = add(res,(1<<idx));
            a = sub(a,b<<idx);
        }
    }
    return res;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

