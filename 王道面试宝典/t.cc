#include <string.h>
#include <stdio.h>
#include <cstdio>
#include <iostream>
using namespace std;
char g_array[8]  = {0};

void init_array(char *array)
{
    if(array == NULL)
    {
        return ;
    }
    snprintf(array,sizeof(array),"Hello World!");
}
int main()
{
    init_array(g_array);
    printf("%s\n",g_array);
    return 0;
}

