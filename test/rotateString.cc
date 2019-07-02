#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Solution
{

bool find()
{
    char src[]="AABBCD";
    char des[]="CDAA";

    int len = strlen(src);
    for(int i = 0;i<len;++i)
    {
        char tempchar =src[0];
        for(int j = 0;j<len-1;j++)
        {
            src[j] = src[j+1];
        }
        src[len-1]=tempchar;
        if(strstr(src,des)==0)
        {
            return (true);
        }
    }
    return true;
}

};
