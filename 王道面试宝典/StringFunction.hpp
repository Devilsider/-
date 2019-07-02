#pragma once
//实现string库函数
#include <assert.h>

#include <iostream>

using namespace std;
class StringFunction
{
public:
    int strlen(const char *str)
    {
        assert(str!=NULL);

        int len =0;
        while((*str++)!='\0')
        {
            ++len;
        }
        return len;
    }
    
    int strcmp(const char *str1,const char *str2)
    {
        assert(str1!=NULL&&str2!=NULL);
        int ret=0;
        while(!(ret = *(unsigned char *)str1-*(unsigned char *)str2)&&*str1)
        {
            ++str1;
            ++str2;
        }
        if(ret<0)
        {
            ret=-1;
        }
        else if(ret>0)
        {
            ret=1;
        }
        return ret;
    }
    
    char *strcat(char *strDest,const char *strSrc)
    {
        char *address = strDest;
        assert((strDest != NULL)&&(strSrc!=NULL));
        while(*strDest)
        {
            ++strDest;
        }
        while((*strDest++ = *strSrc++)!='\0');
        return address;
    }

    char *strcpy(char *strDest,const char* strSrc)
    {
        assert(strDest!=NULL&&strSrc!=NULL);
        char *strD = strDest;
        while((*strDest++ = *strSrc++)!='\0');
        return strD;
    }
};

