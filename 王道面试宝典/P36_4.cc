#include <string.h>

#include <iostream>

void removeDuplicates(char * str)
{
    if(str == NULL)
    {
        return;
    }
    int len = strlen(str);
    if(len<2)
    {
        return;
    }
    int tail = 1;
    for(int i=1;i<len;++i)
    {
        int j;
        for(j=0;j<tail;++j)
        {
            if(str[i]==str[j])
            {
                break;
            }
        }
        if(j==tail)
        {
            str[tail]=str[i];
            ++tail;
        }
    }
    str[tail]=0;
}

void removeDuplicatesHash(char str[])
{
    if(str==NULL)
    {
        return ;
    }
    int len = strlen(str);
    if(len<2)
    {
        return;
    }
    bool hit[256];
    for(int i=0;i<256;++i)
    {
        hit[i]=false;
    }
    hit[(int)str[0]]=true;
    int tail=1;
    for(int i=1;i<len;++i)
    {
        if(!hit[(int)str[i]])
        {
            str[tail]=str[i];
            ++tail;
            hit[(int)str[i]]=true;
        }
    }
    str[tail]=0;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

