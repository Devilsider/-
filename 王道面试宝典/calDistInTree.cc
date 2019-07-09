#include <iostream>
using namespace std;

struct NODE
{
    NODE * pLeft;
    NODE * pRight;
    int nMaxLeft;
    int nMaxRight;
    char chValue;
};

int nMaxLen = 0;
void FindMaxLen(NODE *pRoot)
{
    //遍历到叶子节点返回
    if(pRoot ==NULL)
    {
        return;
    }
    if(pRoot->pLeft==NULL)
    {
        pRoot->nMaxLeft = 0;
    }
    if(pRoot->pRight==NULL)
    {
        pRoot->nMaxRight = 0;
    }
    if(pRoot->pLeft!=NULL)
    {
        FindMaxLen(pRoot->pLeft);
    }
    if(pRoot->pRight!=NULL)
    {
        FindMaxLen(pRoot->pRight);
    }
    if(pRoot->pLeft!=NULL)
    {
        int nTempMax = 0;
        if(pRoot->pLeft->nMaxLeft > pRoot->pLeft->nMaxRight)
        {
            nTempMax = pRoot->pLeft->nMaxLeft;
        }else {
            nTempMax = pRoot->pLeft->nMaxRight;
        }
        pRoot->nMaxLeft = nTempMax+1;
    }
    if(pRoot->pRight!=NULL)
    {
        int nTempMax = 0;
        if(pRoot->pRight->nMaxLeft > pRoot->pRight->nMaxRight){
            nTempMax = pRoot->pRight->nMaxLeft;
        }else {
            nTempMax = pRoot->pRight->nMaxRight;
        }
        pRoot->nMaxRight = nTempMax +1;
    }
    if(pRoot->nMaxLeft+pRoot->nMaxRight > nMaxLen)
    {
        nMaxLen = pRoot->nMaxLeft+pRoot->nMaxRight;
    }
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

