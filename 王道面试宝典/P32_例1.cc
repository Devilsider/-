#include <iostream>
#include <string>
using namespace std;
void Reverse(char *pb,char *pe)
{
    //提取出翻转函数，复用代码！！！ 
    if(pb==NULL||pe==NULL){
        return ;
    }
    while(pb<pe)
    {
        char tmp = *pb;//交换pb和pe的内容
        *pb = *pe;
        *pe = tmp;
        ++pb,--pe;
    }
}

char *ReverseSentence(char *pData)
{
    //按空格找到每个单词，将每个单词都逆转
    if(pData == NULL)
    {
        return NULL; 
    }
    char *pBegin = pData;
    char *pEnd = pData;
    while(*pEnd!='\0')
    {
        ++pEnd;
    }
    --pEnd;//去掉空格
    Reverse(pBegin,pEnd);//翻转整个字符串
    pBegin = pEnd =pData;
    while(*pBegin!='\0')
    {
        if(*pBegin == ' ')
        {
            ++pBegin;
            ++pEnd;
            continue;
        }
        //翻转单词
        else if(*pEnd == ' '||*pEnd == '\0')
        {
            Reverse(pBegin,--pEnd);
            pBegin=++pEnd;
        }
        else {
            ++pEnd;
        }
    }
    return pData;
}
int main()
{
    char str[] = "whatever I quit Now!homelossing-dog ha!:)" ;
    ReverseSentence(str) ;
    std::cout<<str<<std::endl;
    return 0;
}

