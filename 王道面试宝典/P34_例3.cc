#include <string.h>

#include <iostream>
using namespace std;
void func(char *s)
{
    int i=0,j=0;
    while(s[j]== ' ')
    {//删除头部空白字符
        ++j;
    }
    int len = strlen(s)-1;
    while(s[len]==' ')
    {
        --len;
    }
    s[len+1]='\0';
    while(s[j]!='\0')
    {
        while(s[j]==' ')
        {
            ++j;
        }
        //将中间的连续的空白符变成一个，判断i！=0是为了防止将头部的连续字符变成1个
        if(s[j-1]==' '&&s[j-2]==' '&&i!=0)
        {
            s[i++]=' ';
        }
        s[i++]=s[j++];
    }
    s[i]='\0';
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

