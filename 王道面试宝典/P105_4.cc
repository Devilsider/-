#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define OFFSET(type,field) ((size_t)&(((type*)0)->field))
using namespace std;

struct S
{
    int a;
    char c;
    int b;
};
int main()
{
    cout<<OFFSET(S,a);
    return 0;
}

