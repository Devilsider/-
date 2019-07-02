#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <iostream>


void multiply(const char *a,const  char*b)
{
    assert(a!=NULL&&b!=NULL);
    int i,j,ca,cb,*s;
    ca = strlen(a);
    cb = strlen(b);
    s = (int *)malloc(sizeof(int)*(ca+cb));//分配存储空间
    for(i=0;i<ca+cb;++i)
    {
        s[i]=0;//每个元素赋予初值0
    }
    for(i=0;i<ca;++i)
    {
        for(j=0;j<cb;++j)
        {
            s[i+j+1]+= (a[i]-'0')*(b[j]-'0');
        }
    }
    for(int idx= 0;idx<ca+cb;++idx)
    {
        std::cout<<s[idx]<<" ";
    }
    std::cout<<std::endl;
    for(i=ca+cb-1;i>=0;--i)
    {
        if(s[i]>=10)
        {
            s[i-1]+=s[i]/10;
            s[i]%=10;
        }
    }
    for(int idx= 0;idx<ca+cb;++idx)
    {
        std::cout<<s[idx]<<" ";
    }
    std::cout<<std::endl;
    char *c = (char *)malloc((ca+cb)*sizeof(char));
    i = 0;
    while(s[i]==0){
        ++i;//跳过头部0元素
    }
    for(j=0;i<ca+cb;++i,++j)
    {
        c[j]=s[i]+'0';
    }
    c[j]='\0';
    for(i=0;i<ca+cb;++i)
    {
        std::cout<<c[i];
    }
    std::cout<<std::endl;
    free(s);
    free(c);

}
int main()
{
    char *a="12345";
    char *b="67899";

    multiply(a,b);

    return 0;
}

