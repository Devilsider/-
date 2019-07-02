#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <iostream>

char *f(char *str,char ch)
{
    char *iter1= str;
    char *iter2 =str;
    while(*iter2!='\0'){
        while(*iter2==ch){
            iter2++;
        }
        *iter1++=*iter2++;
    }
    return str;
}
int main()
{
    char *a = new char[10];
    strcpy(a,"abcdcccd ");
    std::cout<<f(a,'c');
    delete[] a;
    return 0;
}

