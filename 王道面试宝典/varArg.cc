#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int va_sum(int *a,...);

int main()
{
    int number;
    int foo = 0 ;
    foo = va_sum(&number,2,3,4,5,0);
    cout<<foo<<endl;
    return 0;
}
int va_sum(int*a,...)
{
    int counter = 0;
    int element = 0;
    va_list arg;
    va_start(arg,a);
    while((element = va_arg(arg,int))!=0)
    {
        counter += element;
    }
    va_end(arg);
    return counter;
}

